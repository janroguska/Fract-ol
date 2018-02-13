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
	else if (keycode == PLUS)
		e->iteration *= 0.8;
	else if (keycode == MINUS && e->iteration <= 256)
		e->iteration *= 1.2;
	else if (keycode == LEFT)
		e->across += 0.1;
	else if (keycode == RIGHT)
		e->across -= 0.1;
	else if (keycode == UP)
		e->up -= 0.1;
	else if (keycode == DOWN)
		e->up += 0.1;
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
	if ((keycode == 4 || keycode == 1) && e->zoomx > 0.000001)
	{
		e->zoomx *= 0.5;
		e->zoomy *= 0.5;
	}
	else if ((keycode == 5 || keycode == 2) && e->zoomx > 0.000001)
	{
		e->zoomx *= 1.5;
		e->zoomy *= 1.5;
	}
	if (e->fractal == 2)
		draw_julia(e);
	else
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
