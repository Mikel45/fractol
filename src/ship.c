/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:26:09 by crivers           #+#    #+#             */
/*   Updated: 2022/03/14 19:55:19 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	bonus_init(t_vars *vars, t_data *img)
{
	init_inter(vars, img);
	vars->name = 2;
	vars->color = 0;
	vars->left = -2;
	vars->top = -2;
	vars->side = WIN_SIZE / 3.2;
	vars->img = img;
	vars->zoom_x = 3.2;
	vars->zoom_const = 3.2;
}

void	bonus_draw(t_vars *vars)
{
	vars->y = -1;
	while (++vars->y < WIN_SIZE)
	{
		vars->x = -1;
		while (++vars->x < WIN_SIZE)
		{
			mandelbrot_helper(vars);
			while ((vars->zx * vars->zx + vars->zy * vars->zy < 4)
				&& (vars->count < MAX_ITER))
			{
				vars->tempx = fabsl(vars->zx * vars->zx - vars->zy
						* vars->zy + vars->cx);
				vars->zy = fabsl(2 * vars->zx * vars->zy + vars->cy);
				vars->zx = vars->tempx;
				vars->count++;
			}
			my_mlx_pixel_put(vars->img, vars->x, vars->y,
				color(vars->count, vars->color));
		}
	}
}

void	bonus(void)
{
	t_vars	vars;
	t_data	img;

	bonus_init(&vars, &img);
	bonus_draw(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, my_close, &vars);
	mlx_hook(vars.win, 17, 0, destroy, &vars);
	mlx_loop(vars.mlx);
}
