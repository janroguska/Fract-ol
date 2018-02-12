/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:31:05 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/30 15:31:10 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "includes/libft/includes/libft.h"
# include "minilibx/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# define WIDTH 800
# define HEIGHT 600
# define POS(i) (i < 0 ? -i : i)
# define ESC 53
# define MOTION_NOTIFY 6
# define MOTION_MASK (1L<<6)
# define RED 15
# define GREEN 5
# define BLUE 11
# define PURPLE 35

typedef	struct	s_env
{
	int		bits;
	int		sizeline;
	int		endian;
	int		*addr;
	void	*mlx;
	void	*win;
	void	*img;
	double	x0;
	double	y0;
	double	x;
	double	y;
	double	xtemp;
	double	w;
	double	h;
	int		j;
	double	i;
	double	k;
	int		fractal;
	int		colour;
	double	zoomx;
	double	zoomy;
	double	x1;
	double	y1;
	double	xcentre;
	double	ycentre;
	int		iteration;
}				t_env;

int				main(int argc, char **argv);
int				draw(t_env *e);
int				julia(t_env *e);
int				mandelbrot(t_env *e, int row);
//int				mandelbrot(t_env *e);
int				burning_ship(t_env *e);
int				ft_round(double i);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int keycode, int x, int y, t_env *e);
int				tricorn(t_env *e);
void			colour(int j, t_env *e);
int				mouse_move(int x, int y, t_env *e);
int				draw_julia(t_env *e);
void			*fractal(void *row, t_env *e);

#endif
