/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:52:42 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)){}
Point::Point(const Point &point) : x(point.x), y(point.y){}
Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)){}
Point &Point::operator=(const Point &point)
{
	this->x = point.x;
	this->y = point.y;
	return *this;
}
Point::~Point(){}
Fixed Point::getX() const
{
	return this->x;
}
Fixed Point::getY() const
{
	return this->y;
}
