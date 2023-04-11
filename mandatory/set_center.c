/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:29:52 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:29:54 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calculate_center(t_param *par, int *start_x, int *start_y)
{
	int	x_map;
	int	y_map;
	int	half_width_map;
	int	half_height_map;

	x_map = (par->w * par->span) / 2;
	y_map = (par->h * par->span) / 2;
	half_width_map = (x_map - y_map) * cos(THETA);
	half_height_map = (x_map + y_map) * sin(THETA);
	*start_x = (WD_WIDTH / 2) - half_width_map;
	*start_y = (WD_HEIGHT / 2) - half_height_map;
}

void	set_center(t_param *par)
{
	int	col;
	int	row;
	int	start_x;
	int	start_y;

	calculate_center(par, &start_x, &start_y);
	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			par->node[col][row].y += start_y;
			par->node[col][row].x += start_x;
			row++;
		}
		col++;
	}
}
