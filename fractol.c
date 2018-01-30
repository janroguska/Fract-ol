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

int		test_divergence(int c, int k)
{
	double	i;
	int		c2;
	int		k2;

	c2 = 0;
	k2 = 0;
	while (j <= 100)
	{ 
		i = (z * z) + (c + k);
		if (i < z)
			return (0);
		j++;
		z = i;
	}
	return (1);
}

void	draw(t_env *e)
{
	int		i;
	int		j;
	int		k;

	i = 0;
//	while (i < (HEIGHT * WIDTH))
	while (i < HEIGHT)
	{
		k = 0;
		while (k < WIDTH)
		{
			if ((j = test_divergence(0, i, k)) == 1)
				e->addr[i] = 0xFFFFFF;
			else
				e->addr[i] = 0x000000;
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
