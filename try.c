#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_bsh
{
	int	sx;
	int	sy;
	int	step;
	int	*long_leg;
	int	*short_leg;
	int	*long_step;
	int	*short_step;
	int	dx;
	int	dy;
	int	p;
}	t_bsh;

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

void	bresenham(t_bsh2 p1, t_bsh2 p2);

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

void	dda(t_dda p1, t_dda p2)
{
	float    dx;
	float    dy;
	float    max;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	max = find_max(absolute(dx), absolute(dy));
	dx /= max;
	dy /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		printf("(%d,%d) ", (int)p1.x, (int)p1.y);
		p1.x += dx;
		p1.y += dy;
	}
	printf("\n");
}

// void	long_leg_x(t_bsh2 start, t_bsh2 end, t_bsh bsh)
// {
// 	bsh.p = (2 * bsh.dy) + bsh.dx;
// 	while (start.x < end.x)
// 	{
// 		printf("p:%d\n", bsh.p);
// 		printf("(%d,%d) ", start.x, start.y);
// 		if (bsh.p < 0)
// 		{
// 			bsh.p = bsh.p + (2 * bsh.dy);
// 			start.y += bsh.k;
// 		}
// 		else
// 		{
// 			bsh.p = bsh.p + (2 * bsh.dy) - (2 * bsh.dx);
// 		}
// 		start.x++;
// 	}
// 	printf("\n");
// }

// void	long_leg_y(t_bsh2 start, t_bsh2 end, t_bsh bsh)
// {
// 	bsh.p = (2 * bsh.dx) + bsh.dy;
// 	while (start.y < end.y)
// 	{
// 		printf("(%d,%d) ", start.x, start.y);
// 		if (bsh.p < 0)
// 		{
// 			bsh.p = bsh.p + (2 * bsh.dx);
// 			start.x++;
// 		}
// 		else
// 		{
// 			bsh.p = bsh.p + (2 * bsh.dx) - (2 * bsh.dy);
// 		}
// 		start.y += bsh.k;
// 	}
// 	printf("\n");
// }


// void	bresenham(t_bsh2 p1, t_bsh2 p2)
// {
// 	t_bsh	bsh;

// 	bsh.dx = p2.x - p1.x;
// 	bsh.dy = p2.y - p1.y;
// 	if (bsh.dx > 0)
// 	{
// 		bsh.k = 1;
// 		if (bsh.dy < 0)
// 			bsh.k = -1;
// 		bsh.dx = absolute_int(bsh.dx);
// 		bsh.dy = absolute_int(bsh.dy);
// 		if (bsh.dx > bsh.dy)
// 			long_leg_x(p1, p2, bsh);
// 		else
// 			long_leg_y(p1, p2, bsh);
// 	}
// 	else
// 	{
// 		bsh.k = 1;
// 		if (bsh.dy > 0)
// 			bsh.k = -1;
// 		bsh.dx = absolute_int(bsh.dx);
// 		bsh.dy = absolute_int(bsh.dy);
// 		if (bsh.dx > bsh.dy)
// 			long_leg_x(p2, p1, bsh);
// 		else
// 			long_leg_y(p2, p1, bsh);
// 	}
// }

long int	get_elapse_time(void)
{
	struct timeval    time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	bresenham2(t_bsh2 p1, t_bsh2 p2)
{
	int p;
	int dx;
	int dy;

	dx = p2.x - p1.x - 1;
	dy = p2.y - p1.y - 1;
	p = (2 * dy) - dx;
	while (p1.x < p2.x)
	{
		printf("(%d,%d) ", p1.x, p1.y);
		if (p < 0)
		{
			p = p + (2 * dy);
		}
		else
		{
			p = p + (2 * dy) - (2 * dx);
			p1.y++;
		}
		p1.x++;
	}
	printf("\n");
}

void drawLine(int x1, int y1, int x2, int y2) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx, sy, err, e2;
	
	if (x1 < x2) {
		sx = 1;
	} else {
		sx = -1;
	}
	
	if (y1 < y2) {
		sy = 1;
	} else {
		sy = -1;
	}
	
	err = dx - dy;
	int max = dy;
	if (dx > dy)
		max = dx;
	int i = 0;
	
	while (i++ < max) {
		printf("(%d,%d) ", x1, y1);
		// setPixel(x1, y1); // setPixel() is a function that sets a pixel at the specified coordinates
		
		// if (x1 == x2 && y1 == y2) {
		// 	break;
		// }
		
		e2 = 2 * err;
		
		if (e2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		
		if (e2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
}

#define ZERO 0
#define X2 40
#define Y2 5

int	main(void)
{
	t_dda	d1 = {ZERO, ZERO};
	t_dda	d2 = {X2,Y2};
	t_bsh2	b1 = {ZERO,ZERO};
	t_bsh2	b2 = {X2,Y2};

	long int t = get_elapse_time();
	printf("DDA\n");
	dda(d1, d2);
	printf("---------\n");
	printf("Bresenham\n");
	// drawLine(b1.x, b1.y, b2.x, b2.y);
	bresenham2(b1,b2);
	printf("time:%ld\n", get_elapse_time() - t);
	return (0);
} 
