/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:29:31 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:29:33 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	count_map_width(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		i++;
	}
	return (i);
}

int	check_row(t_param *par, char ***map)
{
	int	i;
	int	len1;
	int	len2;

	len1 = count_map_width(map[0]);
	i = 1;
	while (i < par->h)
	{
		len2 = count_map_width(map[i]);
		if (len1 != len2)
			return (0);
		i++;
	}
	par->w = len1;
	return (1);
}

t_node	**malloc_node(int width, int height)
{
	int		i;
	t_node	**node;

	node = malloc(sizeof(t_node *) * (height + 1));
	if (!node)
		return (NULL);
	i = 0;
	while (i < height)
	{
		node[i] = malloc(sizeof(t_node) * width);
		if (!node[i])
			break ;
		i++;
	}
	if (i == height)
		return (node[i] = NULL, node);
	double_free_n((void *)node, i);
	return (NULL);
}

static int	htoi(char *str)
{
	int			i;
	long long	nb;

	i = 0;
	nb = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i += 2;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 16 + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			nb = nb * 16 + (str[i] - 87);
		else if (str[i] >= 'A' && str[i] <= 'F')
			nb = nb * 16 + (str[i] - 55);
		else
			break ;
		i++;
	}
	return (nb);
}

int	load_map_to_node(t_param *par, char ***map)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	while (y < par->h)
	{
		x = 0;
		while (x < par->w)
		{
			tmp = ft_split(map[y][x], ',');
			if (!tmp)
				return (0);
			par->node[y][x].z = (float)(atoi(tmp[0]));
			if (tmp[1] == NULL)
				par->node[y][x].clr = WHITE_PIXEL;
			else
				par->node[y][x].clr = (int)(htoi(tmp[1]));
			double_free((void *)tmp);
			x++;
		}
		y++;
	}
	return (1);
}
