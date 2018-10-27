/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:45:53 by oevtushe          #+#    #+#             */
/*   Updated: 2018/10/07 16:50:40 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_HPP
# define GAMEENTITY_HPP

#include <ncurses.h>
#include <ctime>
#include <iostream>
#include "Coordinate.hpp"

class GameEntity
{
	public:

		GameEntity(void);
		GameEntity(GameEntity const &ent);
		~GameEntity(void);

		void			setPos(Coordinate const &cord);
		Coordinate		getPos(void) const;
		virtual void	drawEntity(void);
		void			clear(void) const;
		void			takeDamage(unsigned int amount);
		int				getHealth(void) const;

		int				isAlive(void) const;

		GameEntity		&operator=(GameEntity const &ent);

	protected:
		Coordinate					_pos;
		unsigned int				_health;
		unsigned int				_lives;
		
		// width, height
		int		_addToPool(GameEntity *entity, GameEntity *_pool[], const unsigned int poolSize);
};

#endif
