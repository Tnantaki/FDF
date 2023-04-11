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

#include "../includes/fdf.h"

void	exit_msg(int code)
{
	ft_putstr_fd("\e[0;31m", 2);
	if (code == 1)
		ft_putstr_fd(ERR_ARG, 2);
	else if (code == 2)
		ft_putstr_fd(ERR_OPN, 2);
	else if (code == 3)
		ft_putstr_fd(ERR_FLE_EX, 2);
	else if (code == 4)
		ft_putstr_fd(ERR_REC, 2);
	ft_putstr_fd("\e[0m", 2);
	exit(0);
}
