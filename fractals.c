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

int		burning_ship(t_env *e)
{
	int		i;

	e->w = 5 / (double)WIDTH;
	e->h = 4 / (double)HEIGHT;
	e->x0 = (e->x1 * e->w) + (e->k * e->w) / e->zoom;
	e->y0 = (e->y1 * e->h) + (e->i * e->h) / e->zoom;
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

int		mandelbrot(t_env *e)
{
	int		i;
	double	xscalechange;
	double	yscalechange;
	double	w1;
	double	h1;

	w1 = (e->scalex1 / (double)WIDTH);
	h1 = (e->scaley1 / (double)HEIGHT);
	e->w = (e->scalex / (double)WIDTH);
	e->h = (e->scaley / (double)HEIGHT);
	xscalechange = w1 - e->w;
	yscalechange = h1 - e->h;
	// e->x0 = (e->k * e->w) + (e->x1 * e->w) * xscalechange;
	// e->y0 = (e->i * e->h) + (e->y1 * e->h) * yscalechange;
	e->x0 = (e->k * e->w);
	e->y0 = (e->i * e->h);
	e->x = 0;
	e->y = 0;
	e->j = 0;
	i = e->zoom;
	i = 0;
	while ((e->x * e->x + e->y * e->y) < 4 && e->j <= 255)
	{
		e->xtemp = ((e->x * e->x) - (e->y * e->y) + e->x0) - (e->scalex / 2);
		e->y = ((2 * e->x * e->y) + e->y0) - (e->scaley / 2);
		e->x = e->xtemp;
		if ((e->x * e->x + e->y * e->y) > 4)
			i = e->j;
		e->j++;
	}
	return (i);
}

int		julia(t_env *e)
{
	int		i;

	e->w = 5 / (double)WIDTH;
	e->h = 4 / (double)HEIGHT;
	e->x0 = (e->k * e->w) - 2.5;
	e->y0 = (e->i * e->h) - 2;
	if (e->x1 > 0 || e->y1 > 0)
	{
		e->x = (e->x1 / ((double)WIDTH / 2) - 1);
		e->y = (e->y1 / ((double)HEIGHT / 2) - 1);
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

int		tricorn(t_env *e)
{
	int		i;

	e->w = 5 / (double)WIDTH;
	e->h = 4 / (double)HEIGHT;
	e->x0 = (e->x1 * e->w) + (e->k * e->w) / e->zoom;
	e->y0 = (e->y1 * e->h) + (e->i * e->h) / e->zoom;
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
