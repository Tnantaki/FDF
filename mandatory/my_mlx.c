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
			node[col][row].y += par->move_x;
			node[col][row].x += par->move_y;
			row++;
		}
		col++;
	}
	render_line(&par->img, node, par->w, par->h);
	*change = 0;
	par->move_x = 0;
	par->move_y = 0;
}

int	key_hook(int keycode, t_param *par)
{
	int	change;

	change = 1;
	printf("keycode:%d\n", keycode);
	if (keycode == KEY_ESC)
		close_win(par);
	else if (keycode == KEY_W || keycode == KEY_UP)
		par->move_y += 15;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		par->move_x -= 15;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		par->move_y -= 15;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		par->move_x += 15;
	else
		change = 0;
	printf("change:%d\n", change);
	if (change)
		change_node(par, par->node, &change);
	return (0);
}
