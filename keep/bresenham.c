#include "../includes/fdf.h"

// bresenham
typedef struct s_bsh
{
	int	p;
	int	dx;
	int	dy;
}	t_bsh;

int	abs_int(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	isometric_int(int *x, int *y, int z)
{
	int	pv_x;
	int	pv_y;

	pv_x = *x;
	pv_y = *y;
	*x = (int)((pv_x - pv_y) * cos(THETA));
	*y = (int)((pv_x + pv_y) * sin(THETA) - z);
}

void	long_leg_y(t_image *img, t_node start, t_node end, t_bsh bsh)
{
	int	k;
	int	ddx;
	int	dxy;

	ddx = 2 * bsh.dx;
	dxy = 2 * (bsh.dx - bsh.dy);
	bsh.p = (2 * bsh.dx) - bsh.dy;
	if (start.y < end.y)
		k = 1;
	else
		k = -1;
	while (start.y != end.y)
	{
		put_pixel_to_image(img, start);
		if (bsh.p < 0)
			bsh.p = bsh.p + ddx;
		else
		{
			bsh.p = bsh.p + dxy;
			start.x ++;
		}
		start.y += k;
	}
}

void	long_leg_x(t_image *img, t_node start, t_node end, t_bsh bsh)
{
	int	k;
	int	ddy;
	int	dxy;

	ddy = 2 * bsh.dy;
	dxy = 2 * (bsh.dy - bsh.dx);
	bsh.p = (2 * bsh.dy) - bsh.dx;
	if (start.y < end.y)
		k = 1;
	else
		k = -1;
	while (start.x != end.x)
	{
		put_pixel_to_image(img, start);
		if (bsh.p < 0)
			bsh.p = bsh.p + ddy;
		else
		{
			bsh.p = bsh.p + dxy;
			start.y += k;
		}
		start.x++;
	}
}

void	bresenham(t_image *img, t_node p1, t_node p2)
{
	t_node	start;
	t_node	end;
	t_bsh	bsh;

	if (p2.x > p1.x)
	{
		start = p1;
		end = p2;
	}
	else
	{
		start = p2;
		end = p1;
	}
	bsh.dx = abs_int(p2.x - p1.x);
	bsh.dy = abs_int(p2.y - p1.y);
	if (bsh.dy > bsh.dx) //slope > 1
		long_leg_y(img, start, end, bsh);
	else //slope < 1
		long_leg_x(img, start, end, bsh);
}

void	render_line_bsh(t_image *img, t_node **node, int width, int height)
{
	int	col;
	int	row;

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