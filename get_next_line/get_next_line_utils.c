/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:33:29 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/24 15:41:04 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_get_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_get_strnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int	ft_get_check_nl(char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (i < len)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_strjoin(char *s1, char *s2, int lens2)
{
	char	*dst;
	int		lens1;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	lens1 = ft_get_strlen(s1);
	dst = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (lens1--)
		dst[i++] = s1[j++];
	j = 0;
	while (lens2--)
		dst[i++] = s2[j++];
	dst[i] = '\0';
	if (s1)
		free(s1);
	return (dst);
}

char	*ft_get_strdup(char *str, char *line, size_t len_str, size_t len_nl)
{
	size_t	len_line;
	size_t	i;

	if (len_nl <= len_str)
		len_line = len_nl;
	else
		len_line = len_str;
	line = malloc((sizeof(char)) * (len_line + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (len_line--)
		line[i++] = *str++;
	line[i] = '\0';
	return (line);
}
