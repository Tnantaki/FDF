#include "includes/fdf.h"

void	double_free(void **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		printf("%d\n", i);
		i++;
	}
	free(ptr);
}

void	double_free_n(void **ptr, int i)
{
	i--;
	if (!ptr)
		return ;
	while (i >= 0)
	{
		free((void *)ptr[i]);
		i--;
	}
	free(ptr);
}

t_node	**malloc_node(int width, int height)
{
	int		i;
	t_node	**node;

	node = malloc(sizeof(t_node *) * (height + 1));
	if (!node)
		return (NULL);
	i = 0;
	while (i < height)
	{
		node[i] = malloc(sizeof(t_node) * width);
		if (!node[i])
			break ;
		i++;
	}
	if (i == height)
		return (node[i] = NULL, node);
	double_free_n((void *)node, i);
	return (NULL);
}


//#include "mlx_mac/mlx_int.h"
#include <string.h>

int	main(void)
{
	int		width = 20;
	int		height = 10;
	t_param	par;

	printf("Hello\n");
	// printf("sizeof par:%lu\n", sizeof(*par));
//	par.mlx = mlx_init();
//	free((mlx_img_list_t)par.mlx.font);
//	free(par.mlx);
	// par.win = mlx_new_window(par.mlx, 500, 500, "fdf");
	// t_node **str = malloc_node(width, height); 
	// printf("%p\n", str[height - 1]);
	// double_free((void **)str);
	// free_node(str);
	// while (1);
	// mlx_loop(par.mlx);
	char *str = strdup("Sawatdee");
	printf("%s\n", str);
	free(str);
}

// int	init_window(t_param *par)
// {
// 	if (par->mlx == NULL)
// 	{
// 		double_free((void *)par->node);
// 		return (0);
// 	}
// 	if (par->win == NULL)
// 	{
// 		double_free((void *)par->node);
// 		free(par->mlx);
// 		return (0);
// 	}
// 	return (1);
// }
