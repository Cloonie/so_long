/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:49:13 by mliew             #+#    #+#             */
/*   Updated: 2022/08/31 15:37:32 by mliew            ###   ########.fr       */
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
					vars->m_count = 0;
			else if (vars->map[vars->map_y][vars->map_x] == 'P')
				vars->p_check += 1;
			else if (vars->map[vars->map_y][vars->map_x] == 'E')
				vars->exit_check += 1;
			else
				terminate(vars, "Error\nInvalid map character.");
			vars->map_x++;
		}
		vars->map_y++;
	}
	if (vars->p_check != 1 || vars->exit_check != 1)
		terminate(vars, "Error\nPlayer/Exit not found or has duplicate.");
}

void	check_walls(t_vars *vars)
{
	int	error;

	error = 0;
	vars->yend = vars->map_y - 1;
	vars->xend = vars->map_x - 1;
	while (vars->map[vars->yy])
	{
		if (vars->map[0][vars->xx] != '1')
			error++;
		if (vars->map[vars->yend][vars->xx] != '1')
			error++;
		if (vars->map[vars->yy][0] != '1')
			error++;
		if (vars->map[vars->yy][vars->xend] != '1')
			error++;
		if (error > 0
			|| ft_strlen(vars->map[0]) != ft_strlen(vars->map[vars->yy]))
			terminate(vars, "Error\nWalls not surrounding map.");
		if ((vars->xx == vars->xend) && (vars->yy == vars->yend))
			break ;
		vars->xx++;
		vars->yy++;
	}
}

void	print_bgwall(t_vars *vars)
{
	vars->xx = 0;
	vars->yy = 0;
	while (vars->map[vars->yy])
	{
		while (vars->map[vars->yy][vars->xx])
		{
			if (vars->map[vars->yy][vars->xx] == '0' ||
				vars->map[vars->yy][vars->xx] == 'C' ||
				vars->map[vars->yy][vars->xx] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->bg_img, vars->xx * 64, vars->yy * 64);
			else if (vars->map[vars->yy][vars->xx] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img,
					vars->xx * 64, vars->yy * 64);
			else if (vars->map[vars->yy][vars->xx] == 'E')
			{
				vars->exit_y = vars->yy;
				vars->exit_x = vars->xx;
			}
			vars->xx++;
		}
		vars->xx = 0;
		vars->yy++;
	}
}

void	print_staticimg(t_vars *vars)
{
	vars->xx = 0;
	vars->yy = 0;
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

int	exit_condition(t_vars *vars)
{
	while (vars->bar <= vars->map_x)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bar_img,
			vars->bar++ *64, vars->map_y * 64);
	vars->bar = 0;
	mlx_string_put(vars->mlx, vars->win, 25, vars->map_y * 64 + 15, 0,
		ft_strjoin("Movement Count: ", ft_itoa(vars->m_count)));
	if (vars->map[vars->p_y][vars->p_x] == 'C')
	{
		vars->col_collect++;
		vars->map[vars->p_y][vars->p_x] = '0';
	}
	if (vars->map[vars->p_y][vars->p_x] == 'E' &&
			vars->col_collect == vars->col_count)
		terminate(vars, "Victory!");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_img,
		vars->exit_x * 64, vars->exit_y * 64);
	return (0);
}
