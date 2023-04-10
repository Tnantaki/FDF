/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:03:42 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 21:04:06 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#if defined(__linux__)
#include "keycode_linux.h"
#else
#include "keycode_macos.h"
#endif

// Wire length
// #define par ->span 30
#define WD_WIDTH 1920
#define WD_HEIGHT 1080
#define THETA 0.523599
// error system
#define ERR_WIN "Error to create new window\n"
#define ERR_MAL "Error malloc\n"
// error message
#define ERR_ARG "The Program take only one map file argument.\n"
#define ERR_OPN "Can't open map file.\n"
#define ERR_FLE_EX "Filename extension of map must be \".fdf\".\n"
#define ERR_REC "Number of column in each row not equal.\n"
#define ERR_ATT "Altitude number have to be digit.\n"
#define ERR_CLR "Color number have to be dight\n"
// color
//  # define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0x00FF00
// # define YELLOW_PIXEL 0xFFFF00
#define ORANGE_PIXEL 0xFF8000
// # define CYAN_PIXEL 0x00FFFF
// # define BLUE_PIXEL 0x0000FF
// # define PURPLE_PIXEL 0x7F00FF
// # define KRAM_PIXEL 0x3333FF
#define WHITE_PIXEL 0xFFFFFF
// # define BLACK_PIXEL 0xFF000000
// # define TRAN_PIXEL 0xD000FF00
// node
typedef struct s_node
{
	float x;
	float y;
	float z;
	int clr;
} t_node;
// Image structure
typedef struct s_image
{
	void *ptr;
	void *addr;
	int bpp;
	int line_len;
	int endian;
} t_image;
// bresenham variables
typedef struct s_bsh
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	dx;
	float	dy;
	float	p;
	float	max;
	int		clr1;
	int		clr2;
	int		range;
} t_bsh;
// mlx
typedef struct s_param
{
	t_image img;
	t_node **node;
	void *mlx;
	void *win;
	int w;
	int h;
	int span;
} t_param;

// check map1
int		check_filename(char *mapfile);
char	***read_map(t_param *par, char *mapfile);
// check map2
int		check_row(t_param *par, char ***map);
t_node	**allocate_wireframe(t_param *par);
int		altitude_color(t_param *par, char ***map);
// set node
void	set_node(t_param *par);
void	project_isometric(t_node **node, int width, int height);
// set center
void set_center(t_param *par);
// render
void	render_point(t_image *img, t_node **node, int width, int height);
void	render_line(t_image *img, t_node **node, int width, int height);
// my mlx
int		key_hook(int keycode, t_param *par);
// free
void	double_free(void **ptr);
void	triple_free(void ***ptr);
void	double_free_n(void **ptr, int i);
void	triple_free_n(void ***ptr, int i);
// utils
int		ft_strlenchr(const char *str, int c);
void	prt_err_sys(int err);
void	prt_err_msg(int err);
// mlx os
void	init_window(t_param *par);
int		close_win(t_param *par);
void	create_image(t_param *par);
void	put_pixel_to_image(t_image *img, int x, int y, int color);
//equation
float	absolute(float num);
float	find_max(float a, float b);
// void	isometric(t_param *par, int i, int j);
void	isometric(float *x, float *y, float z);
void	bresenham(t_image *img, t_node p1, t_node p2);

#endif
