#include "../includes/fdf.h"

void	bresenham_right(float x1, float y1, float x2, float y2, t_param *par, int color)
{
	float	x = x1;
	float	y = y1;
	float	dx = x2 - x1;
	float	dy = y2 - y1;
	float	p = (2 * dy) + dx;

	while (x < x2)
	{
		put_pixel_to_image(&par->img, x, y, color);
		x++;
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
			y++;
		}
	}
}

void	bresenham_down(float x1, float y1, float x2, float y2, t_param *par, int color)
{
	float	x = x1;
	float	y = y1;
	float	dx = x1 - x2;
	float	dy = y2 - y1;
	float	p = (2 * dy) + dx;

	while (x > x2)
	{
		put_pixel_to_image(&par->img, x, y, color);
		x--;
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
			y++;
		}
	}
}

void	draw_line_right(t_param *par)
{
	int	i;
	int	j;

	i = 0;
	while (i < par->h)
	{
		j = 0;
		while (j + 1< par->w)
		{
			bresenham_right(par->point[i][j].x, par->point[i][j].y, par->point[i][j + 1].x, par->point[i][j + 1].y, par, WHITE_PIXEL);
			j++;
		}
		i++;
	}
}

void	draw_line_down(t_param *par)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < par->h)
	{
		j = 0;
		while (j < par->w)
		{
			bresenham_down(par->point[i][j].x, par->point[i][j].y, par->point[i + 1][j].x, par->point[i + 1][j].y, par, WHITE_PIXEL);
			j++;
		}
		i++;
	}
}
