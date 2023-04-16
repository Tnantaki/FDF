/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:29:12 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:29:17 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_filename(char *mapfile)
{
	int	i;
	int	j;

	if (!mapfile)
		return (0);
	i = 0;
	j = (int)ft_strlen(mapfile) - 4;
	if (j < 0)
		return (0);
	while (mapfile[j])
	{
		if (mapfile[j++] != ".fdf"[i++])
			return (0);
	}
	if (mapfile[j] == '\0')
		return (1);
	return (0);
}

static int	count_line(char *mapfile)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		exit_msg(2);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

static int	ft_gnl_len(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\r' || str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static int	get_map(char ***map, int fd, int height)
{
	char	*line;
	int		y;

	y = 0;
	while (y < height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line[ft_gnl_len(line)] = '\0';
		map[y] = ft_split(line, ' ');
		free(line);
		if (!map[y])
			break ;
		y++;
	}
	if (y == height)
		return (map[y] = NULL, 1);
	triple_free_n((void *)map, y);
	return (0);
}

char	***read_map(t_param *par, char *mapfile)
{
	char	***map;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		exit_msg(2);
	par->h = count_line(mapfile);
	map = malloc(sizeof(char *) * (par->h + 1));
	if (!map)
		return (close(fd), NULL);
	if (get_map(map, fd, par->h) != 1)
		return (close(fd), NULL);
	return (map);
}
