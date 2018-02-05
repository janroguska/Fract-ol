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

	colour = 0x4733FF + j;
	e->addr[ft_round(e->k + (e->i * WIDTH))] = colour;
}

int		burning_ship(t_env *e, t_mouse *m)
{
	int		i;

	e->w = 5 / (double)WIDTH;
	e->h = 3 / (double)HEIGHT;
	e->x0 = (m->x * e->w) + (e->k * e->w) / m->zoom;
	e->y0 = (m->y * e->h) + (e->i * e->h) / m->zoom;
	e->x = 0;
	e->y = 0;
	e->j = 0;
	i = 0;
	while ((e->x * e->x + e->y * e->y) < 4 && e->j <= 255)
	{
		e->xtemp = (POS(e->x * e->x) - POS(e->y * e->y) + e->x0) - 3;
		e->y = (POS(2 * e->x * e->y) + e->y0) - 1.5;
		e->x = e->xtemp;
		if (e->x * e->x + e->y * e->y > 4)
			i = e->j;
		e->j++;
	}
	return (i);
}

int		mandelbrot(t_env *e, t_mouse *m)
{
	int		i;

	e->w = 3.5 / (double)WIDTH;
	e->h = 2 / (double)HEIGHT;
	e->x0 = (m->x * e->w) + (e->k * e->w) / m->zoom;
	e->y0 = (m->y * e->h) + (e->i * e->h) / m->zoom;
	e->x = 0;
	e->y = 0;
	e->j = 0;
	i = 0;
	while ((e->x * e->x + e->y * e->y) < 4 && e->j <= 255)
	{
		e->xtemp = ((e->x * e->x) - (e->y * e->y) + e->x0) - 2.5;
		e->y = ((2 * e->x * e->y) + e->y0) - 1;
		e->x = e->xtemp;
		if ((e->x * e->x + e->y * e->y) > 4)
			i = e->j;
		e->j++;
	}
	return (i);
}

int		julia(t_env *e, t_mouse *m)
{
	e->w = (5 / (double)WIDTH) * m->zoom;
	e->h = (3 / (double)HEIGHT) * m->zoom;
	e->x0 = ((e->k * e->w) - 2.5) * 5 / 5;
	e->y0 = ((e->i * e->h) - 1.5) * 3 / 3;
	e->x = 0;
	e->y = 0;
	e->j = 0;
	while (e->j <= 255)
	{
		e->xtemp = (e->x0 * e->x0) - (e->y0 * e->y0);
		e->y0 = (2 * e->x0 * e->y0) + e->y;
		e->x0 = e->xtemp + e->x;
		if (e->x0 * e->x0 + e->y0 * e->y0 > 4)
			return (1);
		e->j++;
	}
	return (0);
}

int		tricorn(t_env *e, t_mouse *m)
{
	int		i;

	e->w = 3.5 / (double)WIDTH;
	e->h = 2 / (double)HEIGHT;
	e->x0 = (m->x * e->w) + (e->k * e->w) / m->zoom;
	e->y0 = (m->y * e->h) + (e->i * e->h) / m->zoom;
	e->x = 0;
	e->y = 0;
	e->j = 0;
	i = 0;
	while ((e->x * e->x + e->y * e->y) < 4 && e->j <= 255)
	{
		e->xtemp = ((e->x * e->x) - (e->y * e->y) + e->x0) - 2.5;
		e->y = (-2 * e->x * e->y + e->y0) - 1;
		e->x = e->xtemp;
		if ((e->x * e->x + e->y * e->y) > 4)
			i = e->j;
		e->j++;
	}
	return (i);
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
			if (e->fractal == 2)
				j = julia(e, m);
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
