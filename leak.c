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

int	main(void)
{
	int		width = 20;
	int		height = 10;

	t_node **str = malloc_node(width, height); 
	// printf("%p\n", str[height - 1]);
	double_free((void **)str);
	// free_node(str);
	printf("Hello\n");
}