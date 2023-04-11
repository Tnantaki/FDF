#include <stdio.h>
#include <math.h>
typedef struct s_bsh
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	dx;
	int	dy;
	int	ka;
	int	kb;
	int	*a;
	int	*b;
	int	p;
	int	max;
	int	min;
} t_bsh;

float	absolute(float num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

float	find_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void bresenham_float(float x1, float x2, float y1, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	float max = find_max(absolute(dx), absolute(dy));
	dx /= max;
	dy /= max;
	float x = x1;
	float y = y1;

	int i = 0;
	while (i < max)
	{
		i++;
		// printf("point:%d", i);
		printf("(%d,%d) ", (int)x, (int)y);
		// printf("(%f,%f)\n", x, y);
		x = x1 + round(dx * i);
		y = y1 + round(dy * i);

		// x1 = round((float)x1 + dx * i);
		// y1 += dy;
	}
	printf("\n");
	// printf("X1:%d\n", x1);
}

void	ft_setting(t_bsh *bsh)
{
	int	x = 1;
	int	y = 1;
	bsh->ka = 1;
	bsh->kb = 1;
	bsh->dx = bsh->x2 - bsh->x1;
	bsh->dy = bsh->y2 - bsh->y1;
	if (bsh->dx < 0)
	{
		bsh->dx *= -1;
		x = -1;
	}
	if (bsh->dy < 0)
	{
		bsh->dy *= -1;
		y = -1;
	}
	// bsh.dy = absolute(bsh.y2 - bsh.y1);
	if (bsh->dx > bsh->dy)
	{
		bsh->b = &bsh->x1;
		bsh->a = &bsh->y1;
		bsh->max = bsh->dx;
		bsh->min = bsh->dy;
		bsh->kb = x;
		bsh->ka = y;
	}
	else
	{
		bsh->b = &bsh->y1;
		bsh->a = &bsh->x1;
		bsh->max = bsh->dy;
		bsh->min = bsh->dx;
		bsh->kb = y;
		bsh->ka = x;
	}
}



void bresenham_P(t_bsh bsh)
{
	ft_setting(&bsh);

	bsh.p = (2 * bsh.min) + bsh.max;
	int i;
	i = 0;
	// while ((int)(x1 - x2) || (int)(y1 - y2))
	while (i < bsh.max)
	{
		printf("p:%d ", bsh.p);
		printf("(%d,%d) ", bsh.x1, bsh.y1);
		if (bsh.p < 0)
		{
			bsh.p = bsh.p + (2 * bsh.min);
			*bsh.a += bsh.ka;
		}
		else
			bsh.p = bsh.p + (2 * bsh.min) - (2 * bsh.max);
		*bsh.b += bsh.kb;
		i++;
	}
	printf("\n");
}

void bresenham(float x1, float x2, float y1, float y2)
{
	float	dx = x2 - x1;
	float	dy = y2 - y1;
	float	max = find_max(absolute(dx), absolute(dy));
	dx /= max;
	dy /= max;

	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		printf("(%d,%d) ", (int)x1, (int)y1);
		x1 += dx;
		y1 += dy;
	}
	printf("\n");
}
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
long int	get_elapse_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	main(void)
{
	t_bsh	bsh;
	int x1 = 20;
	int y1 = 20;
	int x2 = 4;
	int y2 = 9;
	bsh.x1 = x1;
	bsh.y1 = y1;
	bsh.x2 = x2;
	bsh.y2 = y2;

	// printf("bresenham\n");
	// bresenham(x1, x2, y1, y2);
	// printf("---------\n");
	// printf("P\n");
	// bresenham_P(bsh);
	// printf("---------\n");
	// printf("float\n");
	// bresenham_float(x1, x2, y1, y2);
	// printf("%d\n", a / b);
	long int t = get_elapse_time();

	int a = 200000000;
	int a2 = 343;
	int a3 = 343;
	int	a4 = 41;
	int	a5 = 89;
	float b = 200000000;
	float b2 = 530;
	float b3 = 343;
	for (int i = 0; i < 10000; i++)
		a = (a / a2) * a3 - 50 + 25 * 2 - a4 + a5;
	// for (int i = 0; i < 10000; i++)
	// 	b = (b / b2) * b3;
	printf("a:%d\n", a);
	// printf("b:%f\n", b);

	printf("time:%ld\n", get_elapse_time() - t);

}
