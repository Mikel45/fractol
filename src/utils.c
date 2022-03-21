/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:36:16 by crivers           #+#    #+#             */
/*   Updated: 2022/03/14 19:13:36 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	color_keys(int keycode, t_vars *vars)
{
	if (keycode == 83)
		vars->color = 0;
	if (keycode == 84)
		vars->color = 1;
	if (keycode == 85)
		vars->color = 2;
	if (keycode == 86)
		vars->color = 3;
	if (keycode == 87)
		vars->color = 4;
	if (keycode == 88)
		vars->color = 5;
	if (keycode == 89)
		vars->color = 6;
	if (keycode == 91)
		vars->color = 7;
}

long int	color(int it, int color)
{
	int	colors[16];

	colors[0] = 0x330000;
	colors[1] = 0x4D004D;
	colors[2] = 0x1A6600;
	colors[3] = 0xCCCC00;
	colors[4] = 0xE600E6;
	colors[5] = 0x00004D;
	colors[6] = 0xFF9900;
	colors[7] = 0x4DFF4D;
	return (colors[color] * (it % 6));
}

void	zoom_helper(int x, int y, t_vars *vars)
{
	vars->zoom_y = vars->zoom_x;
	vars->zoom_x = (vars->zoom_const / vars->zoom);
	vars->left += (vars->zoom_y - vars->zoom_x) / 2;
	vars->top += (vars->zoom_y - vars->zoom_x) / 2;
	vars->scale = vars->zoom_x / WIN_SIZE;
	vars->side = WIN_SIZE / vars->zoom_x;
	x -= WIN_SIZE / 2;
	y -= WIN_SIZE / 2;
	vars->left += (x * (vars->zoom_y / WIN_SIZE)) - (x * vars->scale);
	vars->top += (y * (vars->zoom_y / WIN_SIZE)) - (y * vars->scale);
	if (vars->name == 0)
		mandelbrot_draw(vars);
	if (vars->name == 1)
		julia_draw(vars);
	if (vars->name == 2)
		bonus_draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
