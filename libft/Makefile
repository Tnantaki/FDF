# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 11:35:05 by tnantaki          #+#    #+#              #
#    Updated: 2023/02/10 16:35:07 by tnantaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Executable ###
NAME	= libft.a

### Compilation ###
CC		= gcc
RM		= rm -f
C_FLAGS	= -Wall -Wextra -Werror

### Source Files ###
SRCS	= ft_atoi.c ft_putstr_fd.c ft_split.c ft_strlen.c

### Object Files ###
OBJS	= $(SRCS:.c=.o)

### Rule ###
all: $(NAME)

%o:%c
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re