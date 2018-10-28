/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:09:26 by oevtushe          #+#    #+#             */
/*   Updated: 2018/10/07 18:11:48 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

#include "GameEntity.hpp"

class Bullet : public GameEntity
{

public:

	Bullet(int x, int y, int damage, int pVSe);
	Bullet(Bullet const & bullet);
	~Bullet();

	int	addToBulletPool();
	int getDamage();
	int getPvsE();
	void	drawEntity();
	// void	move(Coordinate &cord);
	Bullet & operator=(Bullet const & bullet);

	static const unsigned int	bulletPoolSize;
	static Bullet				*bulletPool[];
	
private:
	int _damage;
	int _pVSe;

};

#endif
