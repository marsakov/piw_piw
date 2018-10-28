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
	_x(0), _y(0), _health(100), _lives(0)
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
	mvprintw(_y, _x, " ");
}

GameEntity	&GameEntity::operator=(GameEntity const &ent)
{
	if (this != &ent)
	{
		_x = ent._x;
		_y = ent._y;
		_lives = 0;
		_health = 0;
	}
	return (*this);
}

int			GameEntity::getHealth(void) const
{
	return (_health);
}

int			GameEntity::setPos(int x, int y)
{
	if (x <= COLS && x >= 0 && y <= LINES - 1 && y >= 0) {
		_x = x;
		_y = y;
		return (1);
	}
	else
		return (0);
}

void		GameEntity::setX(int x)
{
	_x = x;
}

void		GameEntity::setY(int y)
{
	_y = y;
}

void		GameEntity::takeDamage(unsigned int amount){
	if ((int)(_health - amount) < 0)
		_health = 0;
	else
		_health -= amount;
}

int			GameEntity::getX(void) const
{
	return (_x);
}

int			GameEntity::getY(void) const
{
	return (_y);
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
