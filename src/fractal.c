/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:06:14 by crivers           #+#    #+#             */
/*   Updated: 2022/03/14 19:12:10 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	my_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 123)
		vars->left -= 0.1 / vars->zoom;
	if (keycode == 124)
		vars->left += 0.1 / vars->zoom;
	if (keycode == 125)
		vars->top += 0.1 / vars->zoom;
	if (keycode == 126)
		vars->top -= 0.1 / vars->zoom;
	color_keys(keycode, vars);
	if (vars->name == 0)
		mandelbrot_draw(vars);
	if (vars->name == 1)
		julia_draw(vars);
	if (vars->name == 2)
		bonus_draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (1);
}

int	destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (1);
}

void	input_error(void)
{
	ft_putstr("usage: ./fractol [name]\n");
	ft_putstr("avaliable names:\n\t 1) Mandelbrot\n\t");
	ft_putstr(" 2) Julia1\n\t 3) Julia2\n\t 4) Julia3 \n\t 5) Ship \n");
}

void	get_name(char *name)
{
	if (!ft_strcmp(name, "Mandelbrot"))
		mandelbrot();
	else if (!ft_strcmp(name, "Julia1"))
		julia(1);
	else if (!ft_strcmp(name, "Julia2"))
		julia(2);
	else if (!ft_strcmp(name, "Julia3"))
		julia(3);
	else if (!ft_strcmp(name, "Ship"))
		bonus();
	else
		input_error();
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		get_name(argv[1]);
	else
		input_error();
}
