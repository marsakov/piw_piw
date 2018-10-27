/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coordinate.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:47:50 by oevtushe          #+#    #+#             */
/*   Updated: 2018/10/07 18:27:52 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATE_HPP
# define COORDINATE_HPP

class Coordinate
{
	public:
		Coordinate(void);
		Coordinate(int x, int y);
		Coordinate(Coordinate const &cord);
		~Coordinate(void);

		void	setX(int const &x);
		void	setY(int const &y);
		int		getX(void) const;
		int		getY(void) const;

		Coordinate	&operator=(Coordinate const &cord);
		bool		operator==(Coordinate const &cord);

	private:
		int	_x;
		int	_y;
};

#endif
