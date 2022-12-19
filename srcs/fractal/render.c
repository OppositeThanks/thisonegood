/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/12/09 19:03:22 by lperrin           #+#    #+#             */
/*   Updated: 2022/12/09 19:03:22 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	choose_fractal(t_data *data, double pr, double pi)
{
	if (data->set == 1)
		mandelbrot(data, pr, pi);
	else if (data->set == 2)
		julia(data, pr, pi);
	else
		mandelbrot(data, pr, pi);
}

void	render(t_data *data)
{
	double	pr;
	double	pi;

	data->y = 0;
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			pr = data->min_r + data->x * data->zoom * ((data->max_r
						- data->min_r) / WIDTH);
			pi = data->min_i + data->y * data->zoom * ((data->max_i
						- data->min_i) / HEIGHT);
			choose_fractal(data, pr, pi);
			data->x++;
		}
		data->y++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
