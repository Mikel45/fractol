/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:54:04 by crivers           #+#    #+#             */
/*   Updated: 2022/03/14 19:12:19 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	julia_helper(t_vars *vars)
{
	vars->zx = vars->x / vars->side + vars->left;
	vars->zy = vars->y / vars->side + vars->top;
	vars->count = 0;
}

void	init_inter(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit(-1);
	vars->win = mlx_new_window(vars->mlx, WIN_SIZE, WIN_SIZE, "Fract-ol");
	if (!vars->win)
		exit(-1);
	img->img = mlx_new_image(vars->mlx, WIN_SIZE, WIN_SIZE);
	if (!img->img)
		exit(-1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	vars->zoom = 1;
	vars->color = 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 1 || keycode == 4)
		vars->zoom *= 1.1;
	if (keycode == 2 || keycode == 5)
		vars->zoom /= 1.1;
	zoom_helper(x, y, vars);
	return (0);
}
