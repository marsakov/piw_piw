/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:00:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/10/07 18:11:22 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(int x, int y, int damage, int pVSe) {
	setPos(Coordinate(x, y));
	_damage = damage;
	_pVSe = pVSe;
}

Bullet::Bullet(Bullet const & bullet)
{
	setPos(Coordinate(bullet.getPos().getX(), bullet.getPos().getY()));
}

Bullet::~Bullet() {
	return ;
}

void Bullet::drawEntity() {
	mvprintw(getPos().getY(), getPos().getX(), "*");
}

int		Bullet::getDamage()
{
	return (_damage);
}

int		Bullet::getPvsE() {
	return _pVSe;
}


int		Bullet::addToBulletPool()
{
	unsigned int	cnt;
	Bullet		*cur;

	cnt = 0;
	for (unsigned int i = 0; i < bulletPoolSize; ++i)
	{
		cur = bulletPool[i];
		if (!cur || !cur->isAlive())
		{
			bulletPool[i] = this;
			break ;
		}
		++cnt;
	}
	if (cnt == bulletPoolSize)
		return (0);
	return (1);
}

void	Bullet::move(Coordinate &cord)
{
	_pos = cord;
}

Bullet & Bullet::operator=(Bullet const &bullet) {
	if (this != &bullet)
	{
		setPos(Coordinate(bullet.getPos().getX(), bullet.getPos().getY()));
	}
	return (*this);
}

const unsigned int Bullet::bulletPoolSize = 100;
Bullet	*Bullet::bulletPool[bulletPoolSize];
