/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:47:31 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 18:47:33 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_param *par)
{
	if (keycode == KEY_ESC)
		close_win(par);
	// else if (keycode == KEY_W || keycode == KEY_UP)
	// 	move_player(par, -1, 0);
	// else if (keycode == KEY_A || keycode == KEY_LEFT)
	// 	move_player(par, 0, -1);
	// else if (keycode == KEY_S || keycode == KEY_DOWN)
	// 	move_player(par, 1, 0);
	// else if (keycode == KEY_D || keycode == KEY_RIGHT)
	// 	move_player(par, 0, 1);
	return (0);
}
