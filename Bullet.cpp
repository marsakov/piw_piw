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

Bullet::Bullet(int x, int y, int damage, int pVSe, char c) {
	setPos(x, y);
	_damage = damage;
	_pVSe = pVSe;
	_c[0] = c;
	_c[1] = 0;
}

Bullet::Bullet(Bullet const & bullet)
{
	setPos(bullet.getX(), bullet.getY());
}

Bullet::~Bullet() {
	return ;
}

void Bullet::drawEntity() {
	if (_c[0] == '^')
		attron(COLOR_PAIR(3));
	else
		attron(COLOR_PAIR(2));
	mvprintw(_y, _x, _c);
	attroff(COLOR_PAIR(2));
	attroff(COLOR_PAIR(3));
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

Bullet & Bullet::operator=(Bullet const &bullet) {
	if (this != &bullet)
	{
		setPos(bullet.getX(), bullet.getY());
	}
	return (*this);
}

const unsigned int Bullet::bulletPoolSize = 100;
Bullet	*Bullet::bulletPool[bulletPoolSize];
