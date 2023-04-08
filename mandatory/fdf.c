/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:47:09 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 18:47:11 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(t_param *par, int i, int j)
{
	float	pv_x;
	float	pv_y;

	pv_x = par->point[i][j].x;
	pv_y = par->point[i][j].y;
	par->point[i][j].x = (pv_x - pv_y) * cos(THETA);
	par->point[i][j].y = (pv_x + pv_y) * sin(THETA) - par->point[i][j].z;
}

void	rotate_point(t_param *par)
{
	int	i;
	int	j;

	i = 0;
	while (i < par->h)
	{
		j = 0;
		while (j < par->w)
			isometric(par, i, j++);
		i++;
	}
}

// void	translate(t_param *par)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < par->h)
// 	{
// 		j = 0;
// 		while (j < par->w)
// 		{
// 			par->point[i][j].y = start_y + (i * WIRE_LEN);
// 			par->point[i][j].x = start_x + (j * WIRE_LEN);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	set_center(t_param *par, int rotate)
{
	int	win_cen_w = WD_WIDTH / 2;
	int	win_cen_h = WD_HEIGHT / 2;
	int	x = (par->w * WIRE_LEN) / 2;
	int	y = (par->h * WIRE_LEN) / 2;
	int	img_cen_w;
	int	img_cen_h;
	if (rotate == 1)
	{
		img_cen_w = (x - y) * cos(THETA);
		img_cen_h = (x - y) * cos(THETA);
	}
	else
	{
		img_cen_w = (par->w * WIRE_LEN) / 2;
		img_cen_h = (par->h * WIRE_LEN) / 2;
	}
	int	start_x = win_cen_w - img_cen_w;
	int	start_y = win_cen_h - img_cen_h;
	int	i;
	int	j;

	i = 0;
	while (i < par->h)
	{
		j = 0;
		while (j < par->w)
		{
			par->point[i][j].y += start_y;
			par->point[i][j].x += start_x;
			j++;
		}
		i++;
	}
}
void	set_zero_coordinate(t_param *par)
{
	int	i;
	int	j;

	i = 0;
	while (i < par->h)
	{
		j = 0;
		// printf("11111\n");
		while (j < par->w)
		{
			par->point[i][j].y = (i * WIRE_LEN);
			par->point[i][j].x = (j * WIRE_LEN);
			j++;
		}
		i++;
	}
}

void render_background(t_param *par, int color)
{
	for (int i = 0; i < WD_HEIGHT; i++)
	{
		for (int j = 0; j < WD_WIDTH; j++)
			put_pixel_to_image(&par->img, j, i, color);
	}
	mlx_put_image_to_window(par->mlx, par->win, par->img.ptr, 0, 0);
}

void	check_error(t_param *par, int ac, char **av)
{
	char	***map;
	char	*mapfile;

	if (ac != 2)
		prt_err_msg(1);
	mapfile = av[1];
	if (check_filename(mapfile) != 1)
		prt_err_msg(3);
	map = read_map(par, mapfile);
	if (check_row(par, map) != 1)
		prt_err_msg(4);
	par->point = allocate_wireframe(par);
	if (!par->point)
	{
		triple_free((void *)map);
		prt_err_sys(2);
	}
	if (altitude_color(par, map) != 1)
	{
		triple_free((void *)map);
		double_free((void *)par->point);
		prt_err_sys(2);
	}
}

void	print_xy(t_param *par, char *title)
{
	printf("%s\n", title);
	for (int i = 0; i < par->h; i++)
	{
		for (int j = 0; j < par->w; j++)
		{
			printf("(%d,", (int)(par->point[i][j].x));
			printf("%d)", (int)(par->point[i][j].y));
		}
		printf("\n");
	}
}

int	main(int ac, char **av)
{
	t_param	par;

	check_error(&par, ac, av);
	init_window(&par);
	create_image(&par);
	// rotate_wireframe(&par);
	// set_center(&par);
	set_zero_coordinate(&par);

	print_xy(&par, "Before Rotate");
	rotate_point(&par);
	set_center(&par, 0);
	print_xy(&par, "After Rotate");


	render_point(&par);
	draw_line_right(&par);
	draw_line_down(&par);
	mlx_put_image_to_window(par.mlx, par.win, par.img.ptr, 0, 0);
	// render_wireframe(&par);

	// exit (0);
	mlx_key_hook(par.win, key_hook, &par);
	mlx_hook(par.win, 17, 0, close_win, &par);
	mlx_loop(par.mlx);
}
