/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:31:01 by oevtushe          #+#    #+#             */
/*   Updated: 2018/10/07 17:31:20 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(int x, int y, int damage) {
	setPos(Coordinate(x, y));
	_damage = damage;
}

Player::Player(Player const & player)
{
	setPos(Coordinate(player.getPos().getX(), player.getPos().getY()));
}

Player::~Player() {
	return ;
}

void Player::move(int x, int y) {
	if (x <= COLS && x >= 0) {
		setPos(Coordinate(x, getPos().getY()));
	}
	y++;
}

void Player::shoot(void) {
	Bullet* b = new Bullet(getPos().getX(), getPos().getY() - 1, _damage, 0);

	if (!b->addToBulletPool())
	{
		exit(0);
	}
	return ;
}

void	Player::drawEntity(void) {
	mvprintw(getPos().getY(), getPos().getX(), "X");
}

Player & Player::operator=(Player const &player) {
	if (this != &player)
	{
		setPos(Coordinate(player.getPos().getX(), player.getPos().getY()));
	}
	return (*this);
}
