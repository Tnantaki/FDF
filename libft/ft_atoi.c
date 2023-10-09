/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:02:01 by tnantaki          #+#    #+#             */
/*   Updated: 2022/09/16 18:05:19 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	nb;
	int			negative;
	int			i;

	i = 0;
	nb = 0;
	negative = 1;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			negative = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (nb >= 9223372036854775807 / 10 && str[i] - '0' > 7)
		{
			if (negative == 1)
				return (-1);
			return (0);
		}
		nb = nb * 10 + (str[i++] - '0');
	}
	return (nb * negative);
}
/*
int	main(void)
{
	char INTmax[40] = "2147483647";
	char INTmin[40] = "-2147483648";
	char oINTmax[40] = "2147483648";
	char oINTmin[40] = "-21474836493";
	// printf("test:%ld\n", 2147483650 % 2147483648);
	// printf("atoi\t: %d\n",atoi("   123982p322"));
	// printf("ft_atoi\t: %d\n",ft_atoi("   123982p322"));
	// printf("atoi\t: %d\n",atoi("   +12389 2309"));
	// printf("ft_atoi\t: %d\n",ft_atoi("   +12389 2309"));
	// printf("-----------------\n");
	// printf("atoi Max\t: %d\n",atoi(INTmax));
	// printf("atoi Min\t: %d\n",atoi(INTmin));
	// printf("atoi oMax\t: %d\n",atoi(oINTmax));
	// printf("atoi oMin\t: %d\n",atoi(oINTmin));
	// printf("-----------------\n");
	// printf("atoi Max\t: %d\n",ft_atoi(INTmax));
	// printf("atoi Min\t: %d\n",ft_atoi(INTmin));
	// printf("atoi oMax\t: %d\n",ft_atoi(oINTmax));
	// printf("atoi oMin\t: %d\n",ft_atoi(oINTmin));
	// printf("-----------------\n");
	char n[40];
	sprintf(n, "%lu", -2147483648);
	char n1[40] = "99999999999999999999999999";
	char n2[40] = "-9999999999999999999";
	printf("atoi\t: %d\n",atoi(n1));// + = -1;
	printf("ft_atoi\t: %d\n",ft_atoi(n1));
	printf("atoi\t: %d\n",atoi(n2));// - = 0;
	printf("ft_atoi\t: %d\n",ft_atoi(n2));
	printf("atoi\t: %d\n",atoi("jfef"));// - = 0;
}*/
