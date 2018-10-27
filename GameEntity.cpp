/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:58:30 by oevtushe          #+#    #+#             */
/*   Updated: 2018/10/07 16:50:22 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"

GameEntity::GameEntity(void) :
	_pos(0, 0), _health(100), _lives(0)
{
}

GameEntity::GameEntity(GameEntity const &ent)
{
	*this = ent;
}

GameEntity::~GameEntity(void)
{
}

void GameEntity::drawEntity()
{
}

void GameEntity::clear(void) const
{
	mvprintw(_pos.getY(), _pos.getX(), " ");
}

GameEntity	&GameEntity::operator=(GameEntity const &ent)
{
	if (this != &ent)
	{
		_pos = ent._pos;
		_lives = 0;
		_health = 0;
	}
	return (*this);
}

int			GameEntity::getHealth(void) const
{
	return (_health);
}

void		GameEntity::setPos(Coordinate const &cord)
{
	_pos = cord;
}

void		GameEntity::takeDamage(unsigned int amount){
	if ((int)(_health - amount) < 0)
		_health = 0;
	else
		_health -= amount;
}

Coordinate	GameEntity::getPos(void) const
{
	return (_pos);
}

int		GameEntity::isAlive(void) const
{
	return (_lives || _health);
}

int		GameEntity::_addToPool(GameEntity *entity, GameEntity *pool[], const unsigned int poolSize)
{
	unsigned int	cnt;
	GameEntity		*cur;

	cnt = 0;
	for (unsigned int i = 0; i < poolSize; ++i)
	{
		cur = pool[i];
		if (!cur || !cur->isAlive())
		{
			pool[i] = entity;
			break ;
		}
		++cnt;
	}
	if (cnt == poolSize)
		return (0);
	return (1);
}
