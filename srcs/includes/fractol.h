/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:14:45 by lperrin           #+#    #+#             */
/*   Updated: 2022/12/19 11:32:58 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <stdio.h>
# define HEIGHT 600
# define WIDTH 800
# define MAX_ITERATION 30
# define MANDELBROT 1
# define JULIA 2

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			set;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		max_it;
	double		kr;
	double		ki;
	int			x;
	int			y;
	double		zoom;
	int			xmouse;
	int			ymouse;
	int			color;
	int			color_pattern;
	int			*palette;
}				t_data;

/* typedef struct s_rgba
{
	int			r;
	int			g;
	int			b;
	int			t;

}				t_rgb; */

void			help_mess(t_data *data);
void			clear_exit(int exit_code, t_data *data);
void			init(t_data *data);
void			get_julia_starting_values(t_data *data, int ac, char **av);
int				msg(char *str1, char *str2, int errnbr);
double			ft_atof(char *str);
void			my_scrollhook(double xdelta, double ydelta, void *param);
void			render(t_data *data);
void			my_keyhook(mlx_key_data_t keycode, void *param);
void			julia(t_data *data, double cr, double ci);
void			mandelbrot(t_data *data, double cr, double ci);
int				julia_shift_plus(t_data *data);
int				julia_shift_moins(t_data *data);
void			color_shift(t_data *data);
void			reset_image(t_data *data);
#endif