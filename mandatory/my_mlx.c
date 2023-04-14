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
	t_node	pix;

	pix.clr = BLACK_PIXEL;
	pix.y = 0;
	while (pix.y < WD_HEIGHT)
	{
		pix.x = 0;
		while (pix.x < WD_WIDTH)
		{
			put_pixel_to_image(&par->img, pix);
			pix.x++;
		}
		pix.y++;
	}
	mlx_put_image_to_window(par->mlx, par->win, par->img.ptr, 0, 0);
}

void	calculate_node(t_param *par, t_node **node, int change)
{
	if (change == 1)// zooom
	{
		move_node(node, par);
		par->move_x = 0;
		par->move_y = 0;
	}
	else if (change == 2)// zooom
	{
		init_node(par->node, par);
		project_isometric_node(par->node, par);
		render_line(&par->img, par->node, par);
	}
	my_mlx_clear_image(par);
	render_line(&par->img, node, par);
	mlx_put_image_to_window(par->mlx, par->win, par->img.ptr, 0, 0);
}

int	move_model(int keycode, t_param *par)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		par->move_y -= MOVE_RATIO;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		par->move_x -= MOVE_RATIO;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		par->move_y += MOVE_RATIO;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		par->move_x += MOVE_RATIO;
	else
		return (0);
	return (1);
}

int	zoom_model(int keycode, t_param *par)
{
	if (keycode == KEY_PLUS)
		par->span *= ZOOM_RATIO;
	else if (keycode == KEY_MINUS)
		par->span /= ZOOM_RATIO;
	else
		return (0);
	return (1);
}

int	key_hook(int keycode, t_param *par)
{
	if (keycode == KEY_ESC)
		close_win(par);
	if (move_model(keycode, par) == 1)
	{
		calculate_node(par, par->node, 1);
		return (0);
	}
	else if (zoom_model(keycode, par) == 1)
	{
		calculate_node(par, par->node, 2);
		return (0);
	}
	return (0);
}
