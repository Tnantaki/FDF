#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_node
{
	float	x;
	float	y;
}	t_dda;

typedef struct s_bsh2
{
	int	x;
	int	y;
}	t_bsh2;

typedef struct s_bsh
{
	int	sx;
	int	sy;
	int	step;
	int	*long_leg;
	int	*short_leg;
	int	*long_step;
	int	*short_step;
	int	*d_long;
	int	*d_short;
	int	dx;
	int	dy;
	int	p;
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

void	draw_line(t_bsh2 start, t_bsh2 end, t_bsh bsh)
{
	int	i;

	i = 0;
	printf("dx:%d\n", (*bsh.d_long));
	printf("dy:%d\n", (*bsh.d_short));
	bsh.p = (2 * (*bsh.d_short)) - (*bsh.d_long);
	while (i++ < bsh.step)
	{
		// printf("p:%d\n", bsh.p);
		printf("(%d,%d) ", start.x, start.y);
		printf("p:%d", bsh.p);
		if (bsh.p < 0)
		{
			bsh.p = bsh.p + (2 * (*bsh.d_short));
			(*bsh.short_leg) += (*bsh.short_step);
		}
		else
		{
			bsh.p = bsh.p + (2 * (*bsh.d_short)) - (2 * (*bsh.d_long));
		}
		(*bsh.long_leg) += (*bsh.long_step);
	}
	printf("\n");
}

void	set_quadrant(t_bsh2 p1, t_bsh2 p2, t_bsh *bsh)
{
	bsh->dx = abs_int(bsh->dx);
	bsh->dy = abs_int(bsh->dy);
	bsh->step = max_int(bsh->dx, bsh->dy);
	if (bsh->dx > bsh->dy)
	{
		bsh->long_leg = &p1.x;
		bsh->short_leg = &p1.y;
		bsh->long_step = &bsh->sx;
		bsh->short_step = &bsh->sy;
		bsh->d_long = &bsh->dx;
		bsh->d_short = &bsh->dy;
	}
	else
	{
		bsh->long_leg = &p1.y;
		bsh->short_leg = &p1.x;
		bsh->long_step = &bsh->sy;
		bsh->short_step = &bsh->sx;
		bsh->d_long = &bsh->dy;
		bsh->d_short = &bsh->dx;
	}
}

void	bresenham(t_bsh2 p1, t_bsh2 p2)
{
	t_bsh	bsh;

	bsh.dx = p2.x - p1.x;
	bsh.dy = p2.y - p1.y;
	if (bsh.dx < 0)
		bsh.sx = -1;
	else
		bsh.sx = 1;
	if (bsh.dy < 0)
		bsh.sy = -1;
	else
		bsh.sy = 1;
	set_quadrant(p1, p2, &bsh);
	draw_line(p1, p2, bsh);
}