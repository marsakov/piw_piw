/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:29:54 by oevtushe          #+#    #+#             */
/*   Updated: 2018/10/07 20:43:54 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "GameEntity.hpp"
#include "Bullet.hpp"

class Enemy : public GameEntity
{
	public:
		Enemy(void);
		Enemy(int x, int y, int damage);
		Enemy(Enemy const &enemy);
		~Enemy(void);

		int		move(int rightX, int rigthY);
		void	setRightChap();
		void	setLeftChap();
		void	shoot(void);
		void	drawEntity();
		int		isRightChap(void) const;
		int		isLeftChap(void) const;

		int		addToWarriorPool(Enemy *entity);

		static const unsigned int	warriorPoolSize;
		static Enemy				*warriorPool[];

		Enemy	&operator=(Enemy const &enemy);

	private:
		//int		_index;
		int		_damage;
		int		_rightChap;
		int		_leftChap;
};

#endif
