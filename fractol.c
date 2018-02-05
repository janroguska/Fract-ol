/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:28:16 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/31 17:04:47 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		key_hook(int keycode)
{
	if (keycode == 53)
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
	printf("%d\t%d\n", m.x, m.y);
	draw(e, &m);
	return (0);
}

int		ft_round(double i)
{
	return (i < 0 ? i - 0.5 : i + 0.5);
}

int		main(int argc, char **argv)
{
	t_env	e;
	t_mouse	m;

	m.zoom = 1;
	m.x = 0;
	m.y = 0;
	if (argc != 2)
		return (0);
	if (ft_strcmp("mandelbrot", argv[1]) == 0)
		e.fractal = 0;
	else if (ft_strcmp("burning_ship", argv[1]) == 0)
		e.fractal = 1;
	else if (ft_strcmp("julia", argv[1]) == 0)
		e.fractal = 2;
	else if (ft_strcmp("tricorn", argv[1]) == 0)
		e.fractal = 3;
	else
		exit(0);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, argv[1]);
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.addr = (int*)mlx_get_data_addr(e.img, &e.bits, &e.sizeline, &e.endian);
	draw(&e, &m);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
