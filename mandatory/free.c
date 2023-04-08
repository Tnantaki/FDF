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
