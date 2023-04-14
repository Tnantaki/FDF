/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:29:44 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:29:45 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calculate_begin_span(t_param *par)
{
	int	ratio;

	ratio = par->w;
	if (par->h < par->w)
		ratio = par->h;
	par->span = (WD_HEIGHT / ratio) / 1.5;
}

void	calculate_first_node(t_param *par)
{
	int	x_map;
	int	y_map;
	int	half_width_map;
	int	half_height_map;

	x_map = (par->w * par->span) / 2;
	y_map = (par->h * par->span) / 2;
	half_width_map = (x_map - y_map) * cos(THETA);
	half_height_map = (x_map + y_map) * sin(THETA);
	par->first_x = (WD_WIDTH / 2) - half_width_map;
	par->first_y = (WD_HEIGHT / 2) - half_height_map;
}

void	set_color_as_high(t_node **node, t_param *par)
{
	int	col;
	int	row;

	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			if (node[col][row].z != 0 && node[col][row].clr == WHITE_PIXEL)
				node[col][row].clr = ORANGE_PIXEL;
			row++;
		}
		col++;
	}
}

void	init_node(t_node **node, t_param *par)
{
	int	col;
	int	row;

	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			node[col][row].y = col * par->span;
			node[col][row].x = row * par->span;
			row++;
		}
		col++;
	}
}

void	initiate_node(t_param *par)
{
	par->move_x = 0;
	par->move_y = 0;
	calculate_begin_span(par);
	calculate_first_node(par);
	init_node(par->node, par);
	project_isometric_node(par->node, par);
	set_node_center(par->node, par);
	render_line(&par->img, par->node, par);
}