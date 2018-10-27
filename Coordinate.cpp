/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coordinate.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:50:49 by oevtushe          #+#    #+#             */
/*   Updated: 2018/10/07 18:29:08 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Coordinate.hpp"

Coordinate::Coordinate(void) : _x(0), _y(0)
{
}

Coordinate::Coordinate(int x, int y) : _x(x), _y(y)
{
}

Coordinate::Coordinate(Coordinate const &cord)
{
	*this = cord;
}

Coordinate::~Coordinate(void)
{
}

Coordinate	&Coordinate::operator=(Coordinate const &cord)
{
	if (this != &cord)
	{
		_x = cord._x;
		_y = cord._y;
	}
	return (*this);
}

bool	Coordinate::operator==(Coordinate const &cord)
{
	if (cord._x == _x && cord._y == _y)
		return (true);
	return (false);
}

void	Coordinate::setX(int const &x)
{
	_x = x;
}

void	Coordinate::setY(int const &y)
{
	_y = y;
}

int		Coordinate::getX(void) const
{
	return (_x);
}

int		Coordinate::getY(void) const
{
	return (_y);
}
