/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:49:13 by mliew             #+#    #+#             */
/*   Updated: 2022/08/26 14:14:48 by mliew            ###   ########.fr       */
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
			if (vars->map[vars->map_y][vars->map_x] == '0' ||
				vars->map[vars->map_y][vars->map_x] == '1' ||
				vars->map[vars->map_y][vars->map_x] == 'C')
					vars->map_x++;
			else if (vars->map[vars->map_y][vars->map_x] == 'P'
					&& vars->p_check > 0)
			{
				vars->map_x++;
				vars->p_check = -1;
			}
			else if (vars->map[vars->map_y][vars->map_x] == 'E'
					&& vars->exit_check > 0)
			{
				vars->map_x++;
				vars->exit_check = -1;
			}
			else
				terminate(vars, "Map Error.");
		}
		vars->map_y++;
	}
}

void	check_walls(t_vars *vars)
{
	int	error;
	int	count;
	int	first;
	int	last;
	int	next_line;

	first = 0;
	last = vars->map_x;
	next_line = 0;
	error = 0;
	vars->xx = 0;
	count = (vars->map_x * 2) + ((vars->map_y - 2) * 2);
	while (count != 0)
	{
		count--;
		if (vars->map[0][vars->xx++] != '1')
			error = 1;
		// vars->xx = 0;
		// if (vars->map[vars->map_y][vars->xx++] != '1')
		// 	error = 1;
		// if (vars->map[first++][0] != '1')
		// 	error = 1;
		// if (vars->map[next_line++][last] == '1')
		// 	error = 1;
	}
	if (error == 1)
		terminate(vars, "Map borders not all wall.");
}

void	print_bgwall(t_vars *vars)
{
	while (vars->map[vars->yyy])
	{
		while (vars->map[vars->yyy][vars->xxx])
		{
			if (vars->map[vars->yyy][vars->xxx] == '0' ||
				vars->map[vars->yyy][vars->xxx] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->bg_img, vars->xxx * 64, vars->yyy * 64);
			else if (vars->map[vars->yyy][vars->xxx] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img,
					vars->xxx * 64, vars->yyy * 64);
			else if (vars->map[vars->yyy][vars->xxx] == 'E')
			{
				vars->exit_y = vars->yyy;
				vars->exit_x = vars->xxx;
			}
			vars->xxx++;
		}
		vars->xxx = 0;
		vars->yyy++;
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
	while (vars->map[vars->yy])
	{
		while (vars->map[vars->yy][vars->xx])
		{
			if (vars->map[vars->yy][vars->xx] == 'P')
			{
				vars->p_x = vars->xx;
				vars->p_y = vars->yy;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->pd_img,
					vars->p_x * 64, vars->p_y * 64);
			}
			else if (vars->map[vars->yy][vars->xx] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->col_img,
					vars->xx * 64, vars->yy * 64);
				vars->col_count++;
			}
			vars->xx++;
		}
		vars->xx = 0;
		vars->yy++;
	}
}
