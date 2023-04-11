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

void	calculate_span(t_param *par)
{
	int	ratio;

	ratio = par->w;
	if (par->h < par->w)
		ratio = par->h;
	par->span = (WD_HEIGHT / ratio) / 1.5;
}

void	set_color_as_high(t_node **node, int width, int height)
{
	int	col;
	int	row;

	col = 0;
	while (col < height)
	{
		row = 0;
		while (row < width)
		{
			if (node[col][row].z != 0 && node[col][row].clr == WHITE_PIXEL)
				node[col][row].clr = ORANGE_PIXEL;
			row++;
		}
		col++;
	}
}

void	set_node_position(t_node **node, int width, int height, int span)
{
	int	col;
	int	row;

	col = 0;
	while (col < height)
	{
		row = 0;
		while (row < width)
		{
			node[col][row].y = (col * span);
			node[col][row].x = (row * span);
			row++;
		}
		col++;
	}
}

void	project_isometric(t_node **node, int width, int height)
{
	int	col;
	int	row;

	col = 0;
	while (col < height)
	{
		row = 0;
		while (row < width)
		{
			isometric(&node[col][row].x, &node[col][row].y, node[col][row].z);
			row++;
		}
		col++;
	}
}

void set_node(t_param *par)
{
	calculate_span(par);
	set_color_as_high(par->node, par->w, par->h);
	set_node_position(par->node, par->w, par->h, par->span);
	project_isometric(par->node, par->w, par->h);
	par->move_x = 0;
	par->move_y = 0;
}
