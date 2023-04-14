#include "../includes/fdf.h"

void	move_node(t_node **node, t_param *par)
{
	int	col;
	int	row;

	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			node[col][row].y += par->move_y;
			node[col][row].x += par->move_x;
			row++;
		}
		col++;
	}
}

void	set_node_center(t_node **node, t_param *par)
{
	int	col;
	int	row;

	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			node[col][row].y += par->first_y;
			node[col][row].x += par->first_x;
			row++;
		}
		col++;
	}
}

void	project_isometric_node(t_node **node, t_param *par)
{
	int	col;
	int	row;

	col = 0;
	while (col < par->h)
	{
		row = 0;
		while (row < par->w)
		{
			isometric(&node[col][row]);
			row++;
		}
		col++;
	}
}
