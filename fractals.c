/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:47:56 by jroguszk          #+#    #+#             */
/*   Updated: 2018/02/07 16:47:58 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		burning_ship(t_env *e, t_mouse *m)
{
	int		i;

	e->w = 5 / (double)WIDTH;
	e->h = 4 / (double)HEIGHT;
	e->x0 = (m->x * e->w) + (e->k * e->w) / m->zoom;
	e->y0 = (m->y * e->h) + (e->i * e->h) / m->zoom;
	e->x = 0;
	e->y = 0;
	e->j = 0;
	i = 0;
	while ((e->x * e->x + e->y * e->y) < 4 && e->j <= 255)
	{
		e->xtemp = (POS(e->x * e->x) - POS(e->y * e->y) + e->x0) - 2.5;
		e->y = (POS(2 * e->x * e->y) + e->y0) - 2;
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

	e->w = 5 / (double)WIDTH;
	e->h = 4 / (double)HEIGHT;
	e->x0 = (m->x * e->w) + (e->k * e->w) / m->zoom;
	e->y0 = (m->y * e->h) + (e->i * e->h) / m->zoom;
	e->x = 0;
	e->y = 0;
	e->j = 0;
	i = 0;
	while ((e->x * e->x + e->y * e->y) < 4 && e->j <= 255)
	{
		e->xtemp = ((e->x * e->x) - (e->y * e->y) + e->x0) - 2.5;
		e->y = ((2 * e->x * e->y) + e->y0) - 2;
		e->x = e->xtemp;
		if ((e->x * e->x + e->y * e->y) > 4)
			i = e->j;
		e->j++;
	}
	return (i);
}

int		julia(t_env *e, t_mouse *m)
{
	int		i;

	e->w = 5 / (double)WIDTH;
	e->h = 4 / (double)HEIGHT;
	e->x0 = (e->k * e->w) - 2.5;
	e->y0 = (e->i * e->h) - 2;
	if (m->x > 0 || m->y > 0)
	{
		e->x = (m->x / ((double)WIDTH / 2) - 1);
		e->y = (m->y / ((double)HEIGHT / 2) - 1);
	}
	e->j = 0;
	i = 0;
	while (e->j <= 255)
	{
		e->xtemp = (e->x0 * e->x0) - (e->y0 * e->y0);
		e->y0 = (2 * e->x0 * e->y0) + e->y;
		e->x0 = e->xtemp + e->x;
		if (e->x0 * e->x0 + e->y0 * e->y0 > 4)
			i = e->j;
		e->j++;
	}
	return (i);
}

int		tricorn(t_env *e, t_mouse *m)
{
	int		i;

	e->w = 5 / (double)WIDTH;
	e->h = 4 / (double)HEIGHT;
	e->x0 = (m->x * e->w) + (e->k * e->w) / m->zoom;
	e->y0 = (m->y * e->h) + (e->i * e->h) / m->zoom;
	e->x = 0;
	e->y = 0;
	e->j = 0;
	i = 0;
	while ((e->x * e->x + e->y * e->y) < 4 && e->j <= 255)
	{
		e->xtemp = ((e->x * e->x) - (e->y * e->y) + e->x0) - 2.5;
		e->y = (-2 * e->x * e->y + e->y0) - 2;
		e->x = e->xtemp;
		if ((e->x * e->x + e->y * e->y) > 4)
			i = e->j;
		e->j++;
	}
	return (i);
}
