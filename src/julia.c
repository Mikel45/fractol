/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:11:00 by crivers           #+#    #+#             */
/*   Updated: 2022/03/14 19:55:13 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	julia_init1(t_vars *vars, t_data *img)
{
	init_inter(vars, img);
	vars->name = 1;
	vars->left = -1.2;
	vars->top = -1.1;
	vars->side = WIN_SIZE / 2.2;
	vars->cx = 0;
	vars->cy = -0.8;
	vars->img = img;
	vars->zoom_x = 2.2;
	vars->zoom_const = 2.2;
}

void	julia_init2(t_vars *vars, t_data *img)
{
	init_inter(vars, img);
	vars->name = 1;
	vars->left = -1.2;
	vars->top = -1.1;
	vars->side = WIN_SIZE / 2.2;
	vars->cx = -0.8;
	vars->cy = 0.156;
	vars->img = img;
	vars->zoom_x = 2.2;
	vars->zoom_const = 2.2;
}

void	julia_init3(t_vars *vars, t_data *img)
{
	init_inter(vars, img);
	vars->name = 1;
	vars->left = -1.2;
	vars->top = -1.1;
	vars->side = WIN_SIZE / 2.2;
	vars->cx = -0.999;
	vars->cy = 0.999;
	vars->img = img;
	vars->zoom_x = 2.2;
	vars->zoom_const = 2.2;
}

void	julia_draw(t_vars *vars)
{
	vars->y = -1;
	while (++vars->y < WIN_SIZE)
	{
		vars->x = -1;
		while (++vars->x < WIN_SIZE)
		{
			julia_helper(vars);
			while ((vars->zx * vars->zx + vars->zy * vars->zy < 4)
				&& (vars->count < MAX_ITER))
			{
				vars->tempx = vars->zx * vars->zx - vars->zy
					* vars->zy + vars->cx;
				vars->zy = 2 * vars->zx * vars->zy + vars->cy;
				vars->zx = vars->tempx;
				vars->count++;
			}
			my_mlx_pixel_put(vars->img, vars->x, vars->y,
				color(vars->count, vars->color));
		}
	}
}

void	julia(int name)
{
	t_vars	vars;
	t_data	img;

	if (name == 1)
		julia_init1(&vars, &img);
	if (name == 2)
		julia_init2(&vars, &img);
	if (name == 3)
		julia_init3(&vars, &img);
	julia_draw(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, my_close, &vars);
	mlx_hook(vars.win, 17, 0, destroy, &vars);
	mlx_loop(vars.mlx);
}
