### Executable ###
NAME	= fdf

### Directory ###
LIBFT_PATH	= libft/
GNL_PATH	= get_next_line/
MANDA_PATH	= mandatory/
BONUS_PATH	=

### Source Files ###
MANDA_SRCS	= fdf.c check_map1.c check_map2.c init_node.c set_node.c\
				mlx_macos.c mlx_event.c render.c equation.c free.c utils.c 

LIBFT_SRCS	= ft_strlen.c ft_putstr_fd.c ft_atoi.c ft_split.c

GNL_SRCS	= get_next_line.c get_next_line_utils.c

### Compilation ###
CC		= gcc
RM		= rm -f
C_FLAGS	= -Wall -Wextra -Werror

### OS Flags ###
MLX_DIR		= mlx_mac
MLX_FLAGS	= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit
MLX_HEAD	= -Imlx_mac

### Mandatory Source Files ###
SRCS	=	$(addprefix $(MANDA_PATH), $(MANDA_SRCS))\
			$(addprefix $(LIBFT_PATH), $(LIBFT_SRCS))\
			$(addprefix $(GNL_PATH), $(GNL_SRCS))

OBJS	=	$(SRCS:.c=.o)

### Rule ###
%.o:%.c
	$(CC) $(C_FLAGS) $(MLX_HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
##@make -C $(MLX_DIR)
	$(CC) $(C_FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
##@make clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
