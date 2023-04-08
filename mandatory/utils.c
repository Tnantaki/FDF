/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:47:14 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 18:47:15 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_strlenchr(const char *str, int c)
{
	int		i;
	char	care;

	if (!str)
		return (0);
	i = 0;
	care = (char)c;
	while (str[i] == care)
		i++;
	return (i);
}


void	prt_err_msg(int err)
{
	ft_putstr_fd("\e[0;36m", 1);
	if (err == 1)
		ft_putstr_fd(ERR_ARG, 1);
	else if (err == 2)
		ft_putstr_fd(ERR_OPN, 1);
	else if (err == 3)
		ft_putstr_fd(ERR_FLE_EX, 1);
	else if (err == 4)
		ft_putstr_fd(ERR_REC, 1);
	else if (err == 5)
		ft_putstr_fd(ERR_ATT, 1);
	else if (err == 6)
		ft_putstr_fd(ERR_CLR, 1);
	ft_putstr_fd("\e[0m", 1);
	exit (0);
}

void	prt_err_sys(int err)
{
	ft_putstr_fd("\e[0;31m", 1);
	if (err == 1)
		ft_putstr_fd(ERR_WIN, 1);
	else if (err == 2)
		ft_putstr_fd(ERR_MAL, 1);
	ft_putstr_fd("\e[0m", 1);
	exit (1);
}
