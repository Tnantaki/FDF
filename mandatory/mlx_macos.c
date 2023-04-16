/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_macos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:07:56 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:30:22 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_window(t_param *par)
{
	par->mlx = mlx_init();
	if (par->mlx == NULL)
	{
		double_free((void *)par->node);
		return (0);
	}
	par->win = mlx_new_window(par->mlx, WD_WIDTH, WD_HEIGHT, "fdf");
	if (par->win == NULL)
	{
		double_free((void *)par->node);
		free(par->mlx);
		return (0);
	}
	return (1);
}

int	close_win(t_param *par)
{
	mlx_destroy_window(par->mlx, par->win);
	double_free((void *)par->node);
	free(par->mlx);
	exit (0);
	return (0);
}

int	create_image(t_param *par)
{
	par->img.ptr = mlx_new_image(par->mlx, WD_WIDTH, WD_HEIGHT);
	if (par->img.ptr == NULL)
	{
		mlx_destroy_window(par->mlx, par->win);
		double_free((void *)par->node);
		free(par->mlx);
		return (0);
	}
	par->img.addr = mlx_get_data_addr(par->img.ptr, &par->img.bpp,
			&par->img.line_len, &par->img.endian);
	par->img.bpp /= 8;
	return (1);
}

void	put_pixel_to_image(t_image *img, t_node pix)
{
	unsigned int	*dst;

	if (pix.x >= 0 && pix.x < WD_WIDTH && pix.y >= 0 && pix.y < WD_HEIGHT)
	{
		dst = img->addr + ((int)pix.y * img->line_len + (int)pix.x * img->bpp);
		*dst = (unsigned int)pix.clr;
	}
}
