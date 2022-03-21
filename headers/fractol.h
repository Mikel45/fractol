/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:34:48 by crivers           #+#    #+#             */
/*   Updated: 2022/03/14 19:56:40 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define WIN_SIZE 500
# define MAX_ITER 200

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	int			x;
	int			y;
	int			color;
	int			name;
	int			count;
	void		*mlx;
	void		*win;
	long double	left;
	long double	top;
	long double	zoom;
	long double	side;
	long double	scale;
	long double	zx;
	long double	zy;
	long double	cx;
	long double	cy;
	long double	tempx;
	long double	zoom_x;
	long double	zoom_y;
	long double	zoom_const;
	t_data		*img;
}	t_vars;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		init_fractal(t_vars *vars);
void		init_inter(t_vars *vars, t_data *img);

void		zoom_helper(int x, int y, t_vars *vars);
void		color_keys(int keycode, t_vars *vars);
long int	color(int it, int color);

void		mandelbrot(void);
void		mandelbrot_helper(t_vars *vars);
void		mandelbrot_draw(t_vars *vars);
void		mandelbrot_init(t_vars *vars, t_data *img);
void		julia(int name);
void		julia_helper(t_vars *vars);
void		julia_draw(t_vars *vars);
void		bonus(void);
void		bonus_draw(t_vars *vars);

void		ft_putstr(char *s);
int			ft_strlen(char *s);
int			ft_strcmp(char *s1, char *s2);

int			my_close(int keycode, t_vars *vars);
int			destroy(t_vars *vars);
int			mouse_hook(int keycode, int x, int y, t_vars *vars);

#endif