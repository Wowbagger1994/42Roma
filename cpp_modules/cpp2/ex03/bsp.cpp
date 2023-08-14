/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:52:32 by ebraho            #+#    #+#             */
/*   Updated: 2022/08/10 23:24:10 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

	float totalArea = (((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()))).toFloat());
	totalArea = totalArea < 0 ? totalArea * -1 : totalArea;
	float area1 = (((point.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - point.getY())) + (c.getX() * (point.getY() - b.getY()))).toFloat());
	area1 = area1 < 0 ? area1 * -1 : area1;
	float area2 = (((a.getX() * (point.getY() - c.getY())) + (point.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - point.getY()))).toFloat());
	area2 = area2 < 0 ? area2 * -1 : area2;
	float area3 = (((a.getX() * (b.getY() - point.getY())) + (b.getX() * (point.getY() - a.getY())) + (point.getX() * (a.getY() - b.getY()))).toFloat());
	area3 = area3 < 0 ? area3 * -1 : area3;

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;
	return (area1 + area2 + area3 == totalArea);
}
