/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:31:46 by lperrin           #+#    #+#             */
/*   Updated: 2022/10/17 15:31:46 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	msg(char *str1, char *str2, int errnbr)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	return (errnbr);
}

void	complex_limits(t_data *data)
{
	if (data->set == JULIA)
	{
		data->min_r = -2.0;
		data->max_r = 2.0;
		data->min_i = -2.0;
		data->max_i = data->min_i
			+ (data->max_r - data->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		data->min_r = -2.0;
		data->max_r = 1.0;
		data->max_i = -1.2;
		data->min_i = data->max_i
			+ (data->max_r - data->min_r) * HEIGHT / WIDTH;
	}
}

void	get_julia_starting_values(t_data *data, int ac, char **av)
{
	if (data->set != JULIA || ac == 2)
	{
		data->kr = -0.766667;
		data->ki = -0.090000;
		return ;
	}
	if (ac == 3)
		help_mess(data);
	if (!ft_strchr(av[2], '.'))
		help_mess(data);
	if (!ft_strchr(av[3], '.'))
		help_mess(data);
	data->kr = ft_atof(av[2]);
	data->ki = ft_atof(av[3]);
	if (data->kr > 2.0 || data->kr < -2.0)
		help_mess(data);
	if (data->ki >= 2.0 || data->ki <= -2.0)
		help_mess(data);
}

void init(t_data *data)
{
	data->sx = 2.0;
	data->rx = 0.5;
	data->fx = 1.0;
	complex_limits(data);
}
