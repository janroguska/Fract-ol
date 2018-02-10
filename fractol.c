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

int		ft_round(double i)
{
	return (i < 0 ? i - 0.5 : i + 0.5);
}

int		get_fractal(char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		return (0);
	else if (ft_strcmp("burning_ship", argv) == 0)
		return (1);
	else if (ft_strcmp("julia", argv) == 0)
		return (2);
	else if (ft_strcmp("tricorn", argv) == 0)
		return (3);
	else
		exit(0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	e.zoomx = 5;
	e.zoomy = 4;
	e.x1 = 0;
	e.y1 = 0;
	e.xmax = (double)WIDTH;
	e.ymax = (double)HEIGHT;
	if (argc != 2)
		return (0);
	e.fractal = get_fractal(argv[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, argv[1]);
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.addr = (int*)mlx_get_data_addr(e.img, &e.bits, &e.sizeline, &e.endian);
	draw(&e);
	draw_julia(&e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_hook(e.win, MOTION_NOTIFY, MOTION_MASK, mouse_move, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
