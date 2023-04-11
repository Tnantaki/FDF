/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:31:04 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:31:06 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_xy(t_param *par, char *title)
{
	printf("%s\n", title);
	for (int i = 0; i < par->h; i++)
	{
		for (int j = 0; j < par->w; j++)
		{
			printf("(%d,", (int)(par->node[i][j].x));
			printf("%d)", (int)(par->node[i][j].y));
		}
		printf("\n");
	}
}

void	check_error(t_param *par, int ac, char **av)
{
	char	***map;
	char	*mapfile;

	if (ac != 2)
		exit_msg(1);
	mapfile = av[1];
	if (check_filename(mapfile) != 1)
		exit_msg(3);
	map = read_map(par, mapfile);
	if (check_row(par, map) != 1)
		exit_msg(4);
	par->node = allocate_wireframe(par);
	if (!par->node)
	{
		triple_free((void *)map);
		exit(1);
	}
	if (altitude_color(par, map) != 1)
	{
		triple_free((void *)map);
		double_free((void *)par->node);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_param	par;

	check_error(&par, ac, av);
	init_window(&par);
	create_image(&par);
	set_node(&par);
	// print_xy(&par, "Before Rotate");
	set_center(&par);
	render_point(&par.img, par.node, par.w, par.h);
	render_line(&par.img, par.node, par.w, par.h);
	// print_xy(&par, "After Rotate");
	mlx_put_image_to_window(par.mlx, par.win, par.img.ptr, 0, 0);
	mlx_key_hook(par.win, key_hook, &par);
	mlx_hook(par.win, 17, 0, close_win, &par);
	mlx_loop(par.mlx);
}
