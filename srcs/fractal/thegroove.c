/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thegroove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:31:14 by lperrin           #+#    #+#             */
/*   Updated: 2022/11/23 16:46:04 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_cursorhook(double xpos, double ypos, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->zoom += 0.0;
	if (xpos || ypos)
		;
	render(data);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (xdelta)
		;
	if (ydelta > 0)
		data->zoom -= 0.25;
	else if (ydelta < 0)
		data->zoom += 0.25;
	mlx_cursor_hook(data->mlx, &my_cursorhook, (void *)data);
}

void	move(t_data *data, double dist, char dir)
{
	double	center_r;
	double	center_i;

	center_r = data->max_r - data->min_r;
	center_i = data->max_i - data->min_i;
	if (dir == 'R')
	{
		data->min_r += center_r * dist;
		data->max_r += center_r * dist;
	}
	else if (dir == 'L')
	{
		data->min_r -= center_r * dist;
		data->max_r -= center_r * dist;
	}
	else if (dir == 'D')
	{
		data->min_i -= center_i * dist;
		data->max_i -= center_i * dist;
	}
	else if (dir == 'U')
	{
		data->min_i += center_i * dist;
		data->max_i += center_i * dist;
	}
}

void	my_keyhook(mlx_key_data_t keycede, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycede.key == MLX_KEY_ESCAPE)
		exit(1);
	else if (keycede.key == MLX_KEY_UP || keycede.key == MLX_KEY_W)
		move(param, 0.1, 'U');
	else if (keycede.key == MLX_KEY_DOWN || keycede.key == MLX_KEY_S)
		move(param, 0.1, 'D');
	else if (keycede.key == MLX_KEY_LEFT || keycede.key == MLX_KEY_A)
		move(param, 0.1, 'L');
	else if (keycede.key == MLX_KEY_RIGHT || keycede.key == MLX_KEY_D)
		move(param, 0.1, 'R');
	else
		exit(1);
	render(data);
}
