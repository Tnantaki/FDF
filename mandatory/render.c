/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:47:05 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 18:47:06 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	render_point(t_param *par)
{
	int	i;
	int	j;

	i = 0;
	while (i < par->h)
	{
		j = 0;
		while (j < par->w)
		{
			put_pixel_to_image(&par->img, par->point[i][j].x, par->point[i][j].y, par->point[i][j].clr);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(par->mlx, par->win, par->img.ptr, 0, 0);
}

// void	draw_line_right(t_param *par, int x, int y, int start_x, int start_y)
// {
// 	int	i;
// 	int	y_pix;
// 	int	x_pix;

// 	i = 0;
// 	y_pix = start_y + (y * WIRE_LEN);
// 	x_pix = start_x + (x * WIRE_LEN);
// 	while (i < WIRE_LEN)
// 	{
// 		put_pixel_to_image(&par->img, x_pix + i, y_pix, par->point[y][x].clr);
// 		i++;
// 	}
// }

// void	draw_line_down(t_param *par, int x, int y, int start_x, int start_y)
// {
// 	int	i;
// 	int	y_pix;
// 	int	x_pix;

// 	i = 0;
// 	y_pix = start_y + (y * WIRE_LEN);
// 	x_pix = start_x + (x * WIRE_LEN);
// 	while (i < WIRE_LEN)
// 	{
// 		put_pixel_to_image(&par->img, x_pix, y_pix + i, par->point[y][x].clr);
// 		i++;
// 	}
// }

// void	render_wireframe(t_param *par)
// {
// 	int	y;
// 	int	x;
// 	int	start_x = 50;
// 	int	start_y = 50;

// 	y = 0;
// 	while (y < par->h)
// 	{
// 		x = 0;
// 		while (x < par->w)
// 		{
// 			if (x + 1 != par->w)
// 				draw_line_right(par, x, y, start_x, start_y);
// 			if (y + 1 != par->h)
// 				draw_line_down(par, x, y, start_x, start_y);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(par->mlx, par->win, par->img.ptr, 0, 0);
// }
