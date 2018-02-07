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

int		key_hook(int keycode)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

int		mouse_hook(int keycode, int x, int y, t_env *e)
{
	static	t_mouse	m;

	if (m.zoom == 0)
	{
		m.x = 0;
		m.y = 0;
		m.zoom++;
	}
	if (keycode == 2)
		m.zoom *= 0.9;
	else if (keycode == 1)
		m.zoom *= 1.1;
	if (x >= 0 && y >= 0)
	{
		m.x = x;
		m.y = y;
	}
	if (e->fractal == 2)
		return (0);
	draw(e, &m);
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	t_mouse	m;

	if (x >= 0 && y >= 0)
	{
		m.x = x;
		m.y = y;
	}
	draw_julia(e, &m);
	return (0);
}
