/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:48:23 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/14 21:48:26 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_node(t_node **node, t_param *par)
{
	int	col;
	int	row;

	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			node[col][row].y += par->move_y;
			node[col][row].x += par->move_x;
			row++;
		}
		col++;
	}
}

void	set_node_center(t_node **node, t_param *par)
{
	int	col;
	int	row;

	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			node[col][row].y += par->first_y;
			node[col][row].x += par->first_x;
			row++;
		}
		col++;
	}
}

void	isometric_node(t_node **node, t_param *par)
{
	int	col;
	int	row;

	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			isometric(&node[col][row]);
			row++;
		}
		col++;
	}
}
