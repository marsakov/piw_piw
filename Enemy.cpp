/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:57:38 by oevtushe          #+#    #+#             */
/*   Updated: 2018/10/07 21:16:59 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) : _rightChap(0), _leftChap(0) {
	return;
}

Enemy::Enemy(int x, int y, int damage) : _rightChap(0), _leftChap(0) {
	setPos(Coordinate(x, y));
	_damage = damage;
}

Enemy::Enemy(Enemy const & enemy)
{
	setPos(Coordinate(enemy.getPos().getX(), enemy.getPos().getY()));
}

Enemy::~Enemy() {
	return ;
}

int Enemy::move(int x, int y) {
	if (x <= COLS && x >= 0 && y <= LINES - 2 && y >= 0) {
		setPos(Coordinate(x, y));
		return (1);
	}
	return (0);
}

void Enemy::shoot(void) {
	char c;
	Bullet* b = new Bullet(getPos().getX(), getPos().getY() + 1, _damage, 1);

	if (!b->addToBulletPool())
	{
		mvprintw(LINES / 2, COLS / 2 - 10, "KEEP CALM [press ENTER]");
		c = 0;
		while (c != '\n')
			c = getch();
		endwin();
		exit(0);
	}
	return ;
}

void Enemy::drawEntity()
{
	mvprintw(getPos().getY(), getPos().getX(), "V");
}

int		Enemy::isRightChap(void) const {
	return _rightChap;
}

int		Enemy::isLeftChap(void) const {
	return _leftChap;
}

void	Enemy::setRightChap(void) {
	_rightChap = 1;
}

void	Enemy::setLeftChap(void) {
	_leftChap = 1;
}

int		Enemy::addToWarriorPool(Enemy *entity)
{
	unsigned int	cnt;
	Enemy		*cur;

	cnt = 0;
	for (unsigned int i = 0; i < warriorPoolSize; ++i)
	{
		cur = warriorPool[i];
		if (!cur || !cur->isAlive())
		{
			warriorPool[i] = entity;
			break ;
		}
		++cnt;
	}
	if (cnt == warriorPoolSize)
		return (0);
	return (1);
}

Enemy &	Enemy::operator=(Enemy const &enemy) {
	if (this != &enemy)
	{
		setPos(Coordinate(enemy.getPos().getX(), enemy.getPos().getY()));
	}
	return (*this);
}

const unsigned int Enemy::warriorPoolSize = 1000;
Enemy	*Enemy::warriorPool[warriorPoolSize];
