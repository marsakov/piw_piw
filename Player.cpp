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
	setPos(x, y);
	_damage = damage;
}

Player::Player(Player const & player)
{
	setPos(player.getX(), player.getY());
}

Player::~Player() {
	return ;
}

void Player::move(int x, int y) {
	if (x <= COLS && x >= 0) {
		setPos(x, _y);
	}
	y++;
}

void Player::shoot(void) {
	Bullet* b = new Bullet(_x, _y - 1, _damage, 0, '^');

	if (!b->addToBulletPool())
	{
		exit(0);
	}
	return ;
}

void	Player::drawEntity(void) {
	attron(COLOR_PAIR(3));
	mvprintw(_y, _x, "}*.*{");
	attroff(COLOR_PAIR(3));
}

void	Player::clear(void) const
{
	mvprintw(_y, _x, "     \n");
}

Player & Player::operator=(Player const &player) {
	if (this != &player)
	{
		setPos(player.getX(), player.getY());
	}
	return (*this);
}
