/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_linux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:07:49 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/12 00:07:50 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_window(t_param *par)
{
	par->mlx = mlx_init();
	if (par->mlx == NULL)
		exit(1);
	par->win = mlx_new_window(par->mlx, WD_WIDTH,
			WD_HEIGHT, "fdf");
	if (par->win == NULL)
	{
		mlx_destroy_display(par->mlx);
		free(par->mlx);
		exit(1);
	}
}

int	close_win(t_param *par)
{
	ft_double_free(par->map.cor);
	mlx_destroy_image(par->mlx, par->img.player);
	mlx_destroy_image(par->mlx, par->img.wall);
	mlx_destroy_image(par->mlx, par->img.space);
	mlx_destroy_image(par->mlx, par->img.collec);
	mlx_destroy_image(par->mlx, par->img.o_exit);
	mlx_destroy_image(par->mlx, par->img.c_exit);
	mlx_destroy_image(par->mlx, par->img.ply_dor);
	mlx_destroy_window(par->mlx, par->win);
	mlx_destroy_display(par->mlx);
	free(par->mlx);
	exit (0);
	return (0);
}
