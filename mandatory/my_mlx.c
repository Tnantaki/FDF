/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:47:31 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:30:44 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_clear_image(t_param *par)
{
	int	y;
	int	x;

	y = 0;
	while (y < WD_HEIGHT)
	{
		x = 0;
		while (x < WD_WIDTH)
		{
			put_pixel_to_image(&par->img, x, y, BLACK_PIXEL);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(par->mlx, par->win, par->img.ptr, 0, 0);
}

void	change_node(t_param *par, t_node **node, int *change)
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
	my_mlx_clear_image(par);
	render_line(&par->img, node, par->w, par->h);
	mlx_put_image_to_window(par->mlx, par->win, par->img.ptr, 0, 0);
	*change = 0;
	par->move_x = 0;
	par->move_y = 0;
}

int	key_hook(int keycode, t_param *par)
{
	int	change;

	change = 1;
	if (keycode == KEY_ESC)
		close_win(par);
	else if (keycode == KEY_W || keycode == KEY_UP)
		par->move_y -= MOVE_RATIO;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		par->move_x -= MOVE_RATIO;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		par->move_y += MOVE_RATIO;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		par->move_x += MOVE_RATIO;
	else
		change = 0;
	if (change)
		change_node(par, par->node, &change);
	return (0);
}
