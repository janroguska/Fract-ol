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

# define WIDTH 1280
# define HEIGHT 720
# define POS(i) (i < 0 ? -i : i)

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
}				t_env;

typedef	struct	s_mouse
{
	double	zoom;
	int		x;
	int		y;
}				t_mouse;

int				main(int argc, char **argv);
int				draw(t_env *e, t_mouse *m);
int				julia(t_env *e, t_mouse *m);
int				mandelbrot(t_env *e, t_mouse *m);
int				burning_ship(t_env *e, t_mouse *m);
int				ft_round(double i);
int				key_hook(int keycode);
int				mouse_hook(int keycode, int x, int y, t_env *e);

#endif
