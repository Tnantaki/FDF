/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:52:49 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/24 15:50:43 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# include <unistd.h>
# include <stdlib.h>

# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_get_strlen(const char *str);
int		ft_get_strnl(char *str);
int		ft_get_check_nl(char *str, int len);
char	*ft_get_strjoin(char *s1, char *s2, int lens2);
char	*ft_get_strdup(char *str, char *line, size_t len_str, size_t len_nl);

#endif
