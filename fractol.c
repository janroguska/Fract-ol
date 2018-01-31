/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:28:16 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/30 15:28:17 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

int		ft_round(double i)
{
	return (i < 0 ? i - 0.5 : i + 0.5);
}

int		test_divergence(double c, double c2)
{
	double	x0;
	double	y0;
	double	x;
	double	y;
	double	xtemp;
	double	w;
	double	h;
	int		j;

	w = (3 / (double)WIDTH) * 1;
	h = (4 / (double)HEIGHT) * 1;
	x0 = ((c * w) - 2) + (3 / 1);
	y0 = ((c2 * h) - 2) + (4 / 1);
	x = 0;
	y = 0;
	j = 0;
	while (j <= 255)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp; 
		if (x * x + y * y > 4)
			return (1);
		j++;
	}
	return (0);
}

void	draw(t_env *e)
{
	double	i;
	int		j;
	double	k;

	i = 0;
	while (i < HEIGHT)
	{
		k = 0;
		while (k < WIDTH)
		{
			if ((j = test_divergence(k, i)) == 1)
				e->addr[ft_round(k + (i * WIDTH))] = 0xFFFFFF;
			else
				e->addr[ft_round(k + (i * WIDTH))] = 0x000000;
			k++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
		return (0);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, argv[1]);
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.addr = (int*)mlx_get_data_addr(e.img, &e.bits, &e.sizeline, &e.endian);
	draw(&e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
