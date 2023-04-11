/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:31:12 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:31:13 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	absolute(float num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

float	find_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	isometric(float *x, float *y, float z)
{
	float	pv_x;
	float	pv_y;

	pv_x = *x;
	pv_y = *y;
	*x = (pv_x - pv_y) * cos(THETA);
	*y = (pv_x + pv_y) * sin(THETA) - z;
}

void	dda(t_image *img, t_node p1, t_node p2)
{
	float	dx;
	float	dy;
	float	max;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	max = find_max(absolute(dx), absolute(dy));
	dx /= max;
	dy /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		put_pixel_to_image(img, (int)p1.x, (int)p1.y, p1.clr);
		p1.x += dx;
		p1.y += dy;
	}
}
