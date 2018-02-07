/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:13:48 by jroguszk          #+#    #+#             */
/*   Updated: 2018/02/02 10:14:00 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colour(int j, t_env *e)
{
	int		colour;
	int		red;
	int		green;
	int		blue;

	red = j;
	green = j;
	blue = j;
	colour = red + green + blue;
	e->addr[ft_round(e->k + (e->i * WIDTH))] = colour;
}

int		draw_julia(t_env *e, t_mouse *m)
{
	int		j;

	if (e->fractal != 2)
		return (0);
	e->i = 0;
	while (e->i < HEIGHT)
	{
		e->k = 0;
		while (e->k < WIDTH)
		{
			j = julia(e, m);
			if (j != 0)
				colour(j, e);
			else
				e->addr[ft_round(e->k + (e->i * WIDTH))] = 0x000000;
			e->k++;
		}
		e->i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		draw(t_env *e, t_mouse *m)
{
	int		j;

	e->i = 0;
	while (e->i < HEIGHT)
	{
		e->k = 0;
		while (e->k < WIDTH)
		{
			if (e->fractal == 0)
				j = mandelbrot(e, m);
			if (e->fractal == 1)
				j = burning_ship(e, m);
			if (e->fractal == 3)
				j = tricorn(e, m);
			if (j != 0)
				colour(j, e);
			else
				e->addr[ft_round(e->k + (e->i * WIDTH))] = 0x000000;
			e->k++;
		}
		e->i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
