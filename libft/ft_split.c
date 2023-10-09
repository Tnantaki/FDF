/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 09:51:11 by tnantaki          #+#    #+#             */
/*   Updated: 2022/09/15 15:41:12 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	cw;

	i = 0;
	cw = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			if (s[i] == c || s[i] == '\0')
				cw++;
		}
	}
	return (cw);
}

static char	*ft_malloc_word(const char *str, char c, int *start)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[*start] == c)
		*start += 1;
	while (str[*start + len] != c && str[*start + len] != '\0')
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[*start + i];
		i++;
	}
	*start += len;
	word[i] = '\0';
	return (word);
}

static char	**ft_freeword(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		cw;
	int		i;
	int		start;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	cw = ft_countword(s, c);
	split = (char **)malloc(sizeof(char *) * (cw + 1));
	if (!split)
		return (NULL);
	while (i < cw)
	{
		split[i] = ft_malloc_word(s, c, &start);
		if (!split[i])
			return (ft_freeword(split, i));
		i++;
	}
	split[i] = NULL;
	return (split);
}
