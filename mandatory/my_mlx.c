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

void	calculate_node(t_param *par, t_node **node)
{
	init_node(node, par);
	isometric_node(node, par);
	set_node_center(node, par);
	move_node(node, par);
	render_line(&par->img, node, par);
	my_mlx_clear_image(par);
	render_line(&par->img, node, par);
	mlx_put_image_to_window(par->mlx, par->win, par->img.ptr, 0, 0);
}

int	key_hook(int keycode, t_param *par)
{
	int	event;

	event = 1;
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
	else if (keycode == KEY_PLUS)
		par->span *= ZOOM_RATIO;
	else if (keycode == KEY_MINUS)
		par->span /= ZOOM_RATIO;
	else
		return (0);
	if (event)
		calculate_node(par, par->node);
	return (0);
}
