/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:49:13 by mliew             #+#    #+#             */
/*   Updated: 2022/08/23 18:56:57 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_mapsize_chars(t_vars *vars)
{
	while (vars->map[vars->map_y])
	{
		vars->map_x = 0;
		while (vars->map[vars->map_y][vars->map_x])
		{
			if (vars->map[vars->map_y][vars->map_x] == 'C')
				vars->map_x++;
			else if (vars->map[vars->map_y][vars->map_x] == '1')
				vars->map_x++;
			else if (vars->map[vars->map_y][vars->map_x] == '0')
				vars->map_x++;
			else if (vars->map[vars->map_y][vars->map_x] == 'E'
					&& vars->exit_x == 0)
			{
				vars->exit_x = vars->map_x;
				vars->exit_y = vars->map_y;
				vars->map_x++;
			}
			else if (vars->map[vars->map_y][vars->map_x] == 'P'
					&& vars->p_x == 0)
			{
				vars->p_x = vars->map_x;
				vars->p_y = vars->map_y;
				vars->map_x++;
			}
			else
				terminate(vars, "Map Error.");
		}
		vars->map_y++;
	}
}

void	print_bg(t_vars *vars)
{
	while (vars->bg_y < vars->map_y * 64)
	{
		vars->bg_x = 0;
		while (vars->bg_x < vars->map_x * 64)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->bg_img, vars->bg_x, vars->bg_y);
			vars->bg_x += 64;
		}
		vars->bg_y += 64;
	}
}

int	exit_condition(t_vars *vars)
{
	if (vars->map[vars->p_y][vars->p_x] == 'C')
	{
		vars->col_collect++;
		vars->map[vars->p_y][vars->p_x] = '0';
	}
	if (vars->map[vars->p_y][vars->p_x] == 'E' &&
			vars->col_collect == vars->col_count)
		terminate(vars, "You WON!!!");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_img,
		vars->exit_x * 64, vars->exit_y * 64);
	return (0);
}

void	print_staticimg(t_vars *vars)
{
	int	yy;
	int	xx;

	yy = 0;
	xx = 0;
	while (vars->map[yy])
	{
		while (vars->map[yy][xx])
		{
			if (vars->map[yy][xx] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img,
					xx * 64, yy * 64);
			else if (vars->map[yy][xx] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->pd_img,
					vars->p_x * 64, vars->p_y * 64);
			else if (vars->map[yy][xx] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->col_img,
					xx * 64, yy * 64);
				vars->col_count++;
			}
			xx++;
		}
		xx = 0;
		yy++;
	}
}
