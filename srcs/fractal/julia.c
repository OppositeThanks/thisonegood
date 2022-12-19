/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:32:33 by lperrin           #+#    #+#             */
/*   Updated: 2022/12/19 12:01:25 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_shift_plus(t_data *data)
{
	data->kr += 0.01;
	data->ki += 0.01;
	render(data);
	return (0);
}

int	julia_shift_moins(t_data *data)
{
	data->kr -= 0.01;
	data->ki -= 0.01;
	render(data);
	return (0);
}

void	julia(t_data *data, double zr, double zi)
{
	int		it;
	double	tmp;

	it = -1;
	while (it++ < MAX_ITERATION)
	{
		mlx_put_pixel(data->img, data->x, data->y, 0x000000FF);
		if ((zr * zr + zi * zi) > 4.0)
		{
			mlx_put_pixel(data->img, data->x, data->y, data->palette[it]);
			break ;
		}
		tmp = 2 * zr * zi + data->kr;
		zr = zr * zr - zi * zi + data->ki;
		zi = tmp;
	}
}
