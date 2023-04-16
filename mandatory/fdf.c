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

#include "fdf.h"

int	check_error(t_param *par, int ac, char **av)
{
	char	***map;
	char	*mapfile;

	if (ac != 2)
		exit_msg(1);
	mapfile = av[1];
	if (check_filename(mapfile) != 1)
		exit_msg(3);
	map = read_map(par, mapfile);
	if (!map)
		return (0);
	if (check_row(par, map) != 1)
		exit_msg(4);
	par->node = malloc_node(par->w, par->h);
	if (!par->node)
		return (triple_free((void *)map), 0);
	if (load_map_to_node(par, map) != 1)
		return (triple_free((void *)map), double_free((void *)par->node), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_param	par;

	if (check_error(&par, ac, av) != 1)
		exit(1);
	if (init_window(&par) != 1)
		exit(1);
	if (create_image(&par) != 1)
		exit(1);
	initiate_node(&par);
	mlx_put_image_to_window(par.mlx, par.win, par.img.ptr, 0, 0);
	mlx_hook(par.win, 2, 1L << 0, key_hook, &par);
	mlx_hook(par.win, 17, 0, close_win, &par);
	mlx_loop(par.mlx);
}
