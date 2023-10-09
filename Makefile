### Executable ###
NAME	= fdf

### Directory ###
LIBFT_DIR	= libft/
GNL_DIR		= get_next_line/
MANDA_DIR	= mandatory/
BONUS_DIR	=

### Compilation ###
CC			= gcc
RM			= rm -f
C_FLAGS		= -Wall -Wextra -Werror
MAN_HEAD	= -Iincludes

### Libft Flags ###
FT_FLAGS	= -Llibft -lft
FT_HEAD		= -Ilibft

### GNL Flags ###
GNL_FLAGS	= -Lget_next_line -lgnl
GNL_HEAD	= -Iget_next_line

### OS Flags ###
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	MANDA_SRCS	= fdf.c check_map1.c check_map2.c init_node.c set_node.c\
				mlx_linux.c mlx_event.c render.c equation.c free.c utils.c 

	MLX_DIR		= mlx_linux
	MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MLX_HEAD	= -Imlx_linux
else
	MANDA_SRCS	= fdf.c check_map1.c check_map2.c init_node.c set_node.c\
				mlx_macos.c mlx_event.c render.c equation.c free.c utils.c 

	MLX_DIR		= mlx_mac
	MLX_FLAGS	= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit
	MLX_HEAD	= -Imlx_mac
endif

### Source Files ###
SRCS	=	$(addprefix $(MANDA_DIR), $(MANDA_SRCS))

### Object Files ###
OBJS	=	$(SRCS:.c=.o)

### Rule ###
%.o:%.c
	$(CC) $(C_FLAGS) $(MAN_HEAD) $(MLX_HEAD) $(FT_HEAD) $(GNL_HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(C_FLAGS) $(OBJS) $(MLX_FLAGS) $(FT_FLAGS) $(GNL_FLAGS) -o $(NAME)

clean:
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(GNL_DIR)
	@make clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
