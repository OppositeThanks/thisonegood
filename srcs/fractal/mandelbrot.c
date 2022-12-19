/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:36:43 by lperrin           #+#    #+#             */
/*   Updated: 2022/12/12 15:51:27 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_data *data, double cr, double ci)
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
		mlx_put_pixel(data->img, data->x, data->y, 0x163156FF);
		if ((zr * zr + zi * zi) > 4.0)
		{
			mlx_put_pixel(data->img, data->x, data->y, 0x782465FF);
			break ;
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
}
