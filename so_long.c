/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:16:45 by mliew             #+#    #+#             */
/*   Updated: 2022/08/12 21:30:51 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_loop(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == W)
		// printf("W");
		vars->y -= 64;
	if (keycode == A)
		// printf("A\n");
		vars->x -= 64;
	if (keycode == S)
		// printf("S\n");
		vars->y += 64;
	if (keycode == D)
		// printf("D\n");
		vars->x += 64;
	return (0);
}

int	img_loop(t_vars *vars)
{
	vars->relative_path = "sprites/pikachu.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->relative_path, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.img_width = 64;
	vars.img_height = 64;
	vars.x = 0;
	vars.y = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "so_long");
	mlx_loop_hook(vars.mlx, img_loop, &vars);
	mlx_key_hook(vars.win, key_loop, &vars);
	mlx_loop(vars.mlx);
}
