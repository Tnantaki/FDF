/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_macos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:07:56 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/12 00:07:57 by tnantaki         ###   ########.fr       */
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
		free(par->mlx);
		exit(1);
	}
}

int	close_win(t_param *par)
{
	double_free((void **)par->map.cor);
	mlx_destroy_window(par->mlx, par->win);
	free(par->mlx);
	exit (0);
	return (0);
}
void	create_image(t_param *par)
{
	par->img.ptr = mlx_new_image(par->mlx, WD_WIDTH, WD_HEIGHT);
	if (par->img.ptr == NULL)
	{
		close_win(par);
		ft_putstr_fd(ERR_WIN, 1);
		exit(1);
	}
	par->img.addr = mlx_get_data_addr(par->img.ptr, &par->img.bpp,
			&par->img.line_len, &par->img.endian);
}

void	put_pixel_to_image(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}
