/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:46:57 by jroguszk          #+#    #+#             */
/*   Updated: 2018/02/07 16:46:58 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == BLUE)
		e->colour = 0;
	else if (keycode == RED)
		e->colour = 1;
	else if (keycode == GREEN)
		e->colour = 2;
	if (e->fractal != 2)
		draw(e);
	else
		draw_julia(e);
	return (0);
}

int		mouse_hook(int keycode, int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0)
	{
		e->x1 = x;
		e->y1 = y;
		e->xcentre += (e->x1 - WIDTH / 2) * e->zoomx;
		e->ycentre += (e->y1 - HEIGHT / 2) * e->zoomy;
	}
	else
		return (0);
	if ((keycode == 7 || keycode == 1) && e->zoomx > 0.000001)
	{
		e->zoomx *= 0.9;
		e->zoomy *= 0.9;
	}
	else if ((keycode == 6 || keycode == 2) && e->zoomx > 0.000001)
	{
		e->zoomx *= 1.1;
		e->zoomy *= 1.1;
	}
	if (e->fractal == 2)
		draw_julia(e);
	draw(e);
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0)
	{
		e->x1 = x;
		e->y1 = y;
	}
	draw_julia(e);
	return (0);
}
