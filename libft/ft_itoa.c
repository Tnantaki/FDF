/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:15:17 by tnantaki          #+#    #+#             */
/*   Updated: 2022/09/15 10:38:54 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countlen(int n, int *sign)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		*sign = -1;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*nb;

	sign = 1;
	i = ft_countlen(n, &sign);
	nb = malloc(sizeof(char) * (i + 1));
	if (!nb)
		return (NULL);
	nb[i--] = '\0';
	if (!n)
	{
		nb[i] = '0';
		return (nb);
	}
	if (n < 0)
		nb[0] = '-';
	while (n)
	{
		nb[i--] = ((n % 10) * sign) + '0';
		n /= 10;
	}
	return (nb);
}
