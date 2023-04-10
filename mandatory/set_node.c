#include "../includes/fdf.h"

void	calculate_span(t_param *par)
{
	int ratio;

	ratio = par->w;
	if (par->h < par->w)
		ratio = par->h;
	par->span = (WD_HEIGHT / ratio) / 1.5;
}

void	set_color_as_high(t_node **node, int width, int height)
{
	int col;
	int row;

	col = 0;
	while (col < height)
	{
		row = 0;
		while (row < width)
		{
			if (node[col][row].z != 0 && node[col][row].clr == WHITE_PIXEL)
				node[col][row].clr = ORANGE_PIXEL;
			row++;
		}
		col++;
	}
}

void	set_node_position(t_node **node, int width, int height, int span)
{
	int col;
	int row;

	col = 0;
	while (col < height)
	{
		row = 0;
		while (row < width)
		{
			node[col][row].y = (col * span);
			node[col][row].x = (row * span);
			row++;
		}
		col++;
	}
}

void	project_isometric(t_node **node, int width, int height)
{
	int col;
	int row;

	col = 0;
	while (col < height)
	{
		row = 0;
		while (row < width)
		{
			// isometric(par->node[col][row].x, par->node[col][row].y, par->node[col][row].z);
			// isometric(par, i, row++);
			isometric(&node[col][row].x, &node[col][row].y, node[col][row].z);
			row++;
		}
		col++;
	}
}

void set_node(t_param *par)
{
	calculate_span(par);
	set_color_as_high(par->node, par->w, par->h);
	set_node_position(par->node, par->w, par->h, par->span);
	project_isometric(par->node, par->w, par->h);
}
