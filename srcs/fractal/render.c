/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:31:28 by lperrin           #+#    #+#             */
/*   Updated: 2022/10/17 15:31:28 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_data *data, int z, double cr, double ci)
{
	int it;
	double zr;
	double zi;
	double tmp;

	zr = 0;
	zi = 0;
	it = -1;
	while (it++ < MAX_ITERATION)
	{
		mlx_put_pixel(data->img, (z / 1000), (z % 1000), 0x00FF00FF);
		if ((zr * zr + zi * zi) > 4.0)
		{
			mlx_put_pixel(data->img, (z / 1000), (z % 1000), 0xFF0000FF);
			break ;
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
}

void	render(t_data *data)
{
	double pr;
	double pi;
	int z;
	t_data img;

	data->y = 0;
	img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			pr = data->min_r + data->x * data->zoom * ((data->max_r - data->min_r) / WIDTH);
			pi = data->min_i + data->y * data->zoom * ((data->max_i - data->min_i) / HEIGHT);
			z = data->x * 1000 + data->y;
			mandelbrot(&img, z, pr, pi);
			data->x++;
		}
		data->y++;
	}
	mlx_image_to_window(data->mlx, img.img, 0, 0);
}
