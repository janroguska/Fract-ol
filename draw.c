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

int		burning_ship(t_env *e, t_mouse *m)
{
	e->w = (5 / (double)WIDTH) * m->zoom;
	e->h = (3 / (double)HEIGHT) * m->zoom;
	e->x0 = ((e->k * e->w) - 3) * WIDTH / m->x;
	e->y0 = ((e->i * e->h) - 1.5) * HEIGHT / m->y;
	e->x = 0;
	e->y = 0;
	e->j = 0;
	while (e->j <= 255)
	{
		e->xtemp = POS(e->x * e->x) - POS(e->y * e->y) + e->x0;
		e->y = POS(2 * e->x * e->y) + e->y0;
		e->x = e->xtemp;
		if (e->x * e->x + e->y * e->y > 4)
			return (1);
		e->j++;
	}
	return (0);
}

int		mandelbrot(t_env *e, t_mouse *m)
{
	e->w = (3.5 / (double)WIDTH) * m->zoom;
	e->h = (2 / (double)HEIGHT) * m->zoom;
	e->x0 = ((e->k * e->w) - 2.5) + m->x;
	e->y0 = ((e->i * e->h) - 1) + m->y;
	e->x = 0;
	e->y = 0;
	e->j = 0;
	while (e->j <= 255)
	{
		e->xtemp = (e->x * e->x) - (e->y * e->y) + e->x0;
		e->y = (2 * e->x * e->y) + e->y0;
		e->x = e->xtemp;
		if (e->x * e->x + e->y * e->y > 4)
			return (1);
		e->j++;
	}
	return (0);
}

int		julia(t_env *e, t_mouse *m)
{
	e->w = (5 / (double)WIDTH) * m->zoom;
	e->h = (3 / (double)HEIGHT) * m->zoom;
	e->x0 = ((e->k * e->w) - 2.5) * 5 / 5;
	e->y0 = ((e->i * e->h) - 1.5) * 3 / 3;
	e->x = 0.0;
	e->y = 0.0;
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
			if (j == 1)
				e->addr[ft_round(e->k + (e->i * WIDTH))] = 0xFFFFFF;
			else
				e->addr[ft_round(e->k + (e->i * WIDTH))] = 0x000000;
			e->k++;
		}
		e->i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
