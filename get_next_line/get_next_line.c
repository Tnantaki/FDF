/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:55:17 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/29 12:30:06 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *str)
{
	int		readable;
	char	*tmp;

	readable = 1;
	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	while (readable)
	{
		readable = read(fd, tmp, BUFFER_SIZE);
		if (readable <= 0)
			break ;
		str = ft_get_strjoin(str, tmp, readable);
		if (ft_get_check_nl(tmp, readable))
			break ;
	}
	free(tmp);
	return (str);
}

static char	*ft_cut_line(char *str, size_t len_str, size_t len_nl)
{
	char	*keep;
	size_t	i;
	size_t	j;

	if (len_nl < len_str)
	{
		i = 0;
		j = len_nl;
		keep = malloc(sizeof(char) * len_str - len_nl + 1);
		if (!keep)
			return (free(str), NULL);
		while (str[j])
			keep[i++] = str[j++];
		keep[i] = '\0';
		free (str);
		return (keep);
	}
	else
		return (free(str), NULL);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	size_t		len_str;
	size_t		len_nl;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_get_check_nl(str, ft_get_strlen(str)))
		str = ft_read_line(fd, str);
	if (str)
	{
		len_str = ft_get_strlen(str);
		len_nl = ft_get_strnl(str) + 1;
		line = ft_get_strdup(str, line, len_str, len_nl);
		str = ft_cut_line(str, len_str, len_nl);
	}
	return (line);
}
