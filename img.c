/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:49:13 by mliew             #+#    #+#             */
/*   Updated: 2022/08/25 17:03:12 by mliew            ###   ########.fr       */
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
		printf("%c\n\n\n", vars->map[0][vars->xx++]);
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
	vars->xx = 0;
	vars->yy = 0;
	while (vars->map[vars->yy])
	{
		while (vars->map[vars->yy][vars->xx])
		{
			if (vars->map[vars->yy][vars->xx] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img,
					vars->xx * 64, vars->yy * 64);
			else if (vars->map[vars->yy][vars->xx] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->pd_img,
					vars->p_x * 64, vars->p_y * 64);
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
