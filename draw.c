/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:13:48 by jroguszk          #+#    #+#             */
/*   Updated: 2018/02/02 10:14:00 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colour(int j, t_env *e)
{
	int		red;
	int		green;
	int		blue;
	double	hex;
	double	tmp;

	tmp = 0;
	while (j >= 1)
	{
		hex = j % 255;
		if (e->colour != 1)
			hex *= 10;
		tmp += hex;
		tmp *= 10;
		j /= 255;
	}
	red = (e->colour == 0 ? (sin(0.016 * tmp + 4) * 230 + 25) : 0xf00000);
	green = (e->colour == 1 ? (sin(0.013 * tmp + 2) * 230 + 25) : 0x0f0000);
	blue = (e->colour == 2 ? (sin(0.01 * tmp + 1) * 230 + 25) : 0x00000f);
	e->addr[ft_round(e->k + (e->i * WIDTH))] = red + green + blue;
}

int		draw_julia(t_env *e)
{
	int		j;

	if (e->fractal != 2)
		return (0);
	e->i = 0;
	while (e->i < HEIGHT)
	{
		e->k = 0;
		while (e->k < WIDTH)
		{
			j = julia(e);
			if (j != 0)
				colour(j, e);
			else
				e->addr[ft_round(e->k + (e->i * WIDTH))] = 0x000000;
			e->k++;
		}
		e->i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		draw(t_env *e)
{
	int		j;

	e->i = 0;
	while (e->i < HEIGHT)
	{
		e->k = 0;
		while (e->k < WIDTH)
		{
			if (e->fractal == 0)
				j = mandelbrot(e);
			if (e->fractal == 1)
				j = burning_ship(e);
			if (e->fractal == 3)
				j = tricorn(e);
			if (j != 0)
				colour(j, e);
			else
				e->addr[ft_round(e->k + (e->i * WIDTH))] = 0x000000;
			e->k++;
		}
		e->i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
