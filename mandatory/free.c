/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:30:53 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:30:55 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	double_free(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	triple_free(void ***ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		double_free((void *)ptr[i]);
		i++;
	}
	free(ptr);
}

void	double_free_n(void **ptr, int i)
{
	i--;
	while (i >= 0)
	{
		free((void *)ptr[i]);
		i--;
	}
	free(ptr);
}

void	triple_free_n(void ***ptr, int i)
{
	i--;
	while (i >= 0)
	{
		double_free((void *)ptr[i]);
		i--;
	}
	free(ptr);
}
