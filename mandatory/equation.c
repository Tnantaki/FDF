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

static float	abs_float(float num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

static float	max_float(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	isometric(t_node *pix)
{
	float	pv_x;
	float	pv_y;

	pv_x = pix->x;
	pv_y = pix->y;
	pix->x = (pv_x - pv_y) * cos(THETA);
	pix->y = (pv_x + pv_y) * sin(THETA) - pix->z;
}

void	dda(t_image *img, t_node p1, t_node p2)
{
	float	dx;
	float	dy;
	float	max;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	max = max_float(abs_float(dx), abs_float(dy));
	dx /= max;
	dy /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		put_pixel_to_image(img, p1);
		p1.x += dx;
		p1.y += dy;
	}
}
