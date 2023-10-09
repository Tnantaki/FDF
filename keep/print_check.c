/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:47:14 by tnantaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:30:01 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
