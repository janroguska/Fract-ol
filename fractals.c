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

void	get_x0_y0(t_env *e)
{
	e->ktmp = e->i / WIDTH;
	e->itmp = e->i % WIDTH;
	e->w = e->zoomx / (double)WIDTH;
	e->h = e->zoomy / (double)HEIGHT;
	e->x0 = e->itmp - WIDTH / 2.0;
	e->y0 = e->ktmp - HEIGHT / 2.0;
	e->x0 = (e->x0 * e->w);
	e->y0 = (e->y0 * e->h);
	e->x0 += (e->xcentre / (double)WIDTH) + e->across;
	e->y0 += (e->ycentre / (double)HEIGHT) + e->up;
}

int		burning_ship(t_env *e)
{
	int		i;

	get_x0_y0(e);
	e->x = 0.0;
	e->y = 0.0;
	e->j = 0;
	i = 0;
	while ((e->x * e->x + e->y * e->y) < 4 && e->j < e->iteration)
	{
		e->xtemp = (POS(e->x * e->x) - POS(e->y * e->y) + e->x0);
		e->y = (POS(2 * e->x * e->y) + e->y0);
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

	get_x0_y0(e);
	e->x = 0;
	e->y = 0;
	e->j = 0;
	i = 0;
	while ((e->x * e->x + e->y * e->y) < 4 && e->j < e->iteration)
	{
		e->xtemp = ((e->x * e->x) - (e->y * e->y) + e->x0);
		e->y = ((2 * e->x * e->y) + e->y0);
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

	get_x0_y0(e);
	if (e->x1 > 0 || e->y1 > 0)
	{
		e->x = (e->x1 / ((double)WIDTH / 2) - 1);
		e->y = (e->y1 / ((double)HEIGHT / 2) - 1);
	}
	e->j = 0;
	i = 0;
	while ((e->x0 * e->x0 + e->y0 * e->y0) < 4 && e->j < e->iteration)
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

	get_x0_y0(e);
	e->x = 0;
	e->y = 0;
	e->j = 0;
	i = 0;
	while ((e->x * e->x + e->y * e->y) < 4 && e->j < e->iteration)
	{
		e->xtemp = ((e->x * e->x) - (e->y * e->y) + e->x0);
		e->y = (-2 * e->x * e->y + e->y0);
		e->x = e->xtemp;
		if ((e->x * e->x + e->y * e->y) > 4)
			i = e->j;
		e->j++;
	}
	return (i);
}
