/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:30:10 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:30:12 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_point(t_image *img, t_node **node, t_param *par)
{
	int	col;
	int	row;

	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			put_pixel_to_image(img, node[col][row]);
			row++;
		}
		col++;
	}
}

void	render_line(t_image *img, t_node **node, t_param *par)
{
	int		col;
	int		row;

	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			if (row + 1 != par->w)
				dda(img, node[col][row], node[col][row + 1]);
			if (col + 1 != par->h)
				dda(img, node[col][row], node[col + 1][row]);
			row++;
		}
		col++;
	}
}
