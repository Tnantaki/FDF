#include "../includes/fdf.h"

void	render_point(t_image *img, t_node **node, int width, int height)
{
	int col;
	int row;

	col = 0;
	while (col < height)
	{
		row = 0;
		while (row < width)
		{
			put_pixel_to_image(img, node[col][row].x
				, node[col][row].y, node[col][row].clr);
			row++;
		}
		col++;
	}
}

void	render_line(t_image *img, t_node **node, int width, int height)
{
	int col;
	int row;

	col = 0;
	while (col < height)
	{
		row = 0;
		while (row < width)
		{
			if (row + 1 != width)
				bresenham(img, node[col][row], node[col][row + 1]);
			if (col + 1 != height)
				bresenham(img, node[col][row], node[col + 1][row]);
			row++;
		}
		col++;
	}
}

