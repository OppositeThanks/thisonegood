/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:06:00 by lperrin           #+#    #+#             */
/*   Updated: 2022/11/23 10:50:57 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	type_cmp(char *av, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

static void	get_set(t_data *data, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm', '1'))
		data->set = MANDELBROT;
	else if (type_cmp(av[1], "julia", 'j', '2'))
		data->set = JULIA;
	else
		help_mess(data);
}

static void	check_args(t_data *data, int ac, char **av)
{
	get_set(data, av);
	if (data->set != JULIA && ac > 3)
		help_mess(data);
	else if (data->set == JULIA && ac > 5)
		help_mess(data);
	get_julia_starting_values(data, ac, av);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.zoom = 1.0;
	if (argc < 2)
		help_mess(&data);
	check_args(&data, argc, argv);
	data.mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", 1);
	if (!data.mlx)
		clear_exit(msg("MLX: error connecting to mlx.", "", 1), &data);
	init(&data);
	render(&data);
	mlx_scroll_hook(data.mlx, &my_scrollhook, ((void *)&data));
	mlx_key_hook(data.mlx, &my_keyhook, ((void *)&data));
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}

/* fractol <type> <options> <color>
M,m,1
J,j,2 */