/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:49:13 by mliew             #+#    #+#             */
/*   Updated: 2022/09/13 13:33:06 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_helper(t_vars *vars)
{
	if (vars->map[vars->map_y][vars->map_x] == '0' ||
		vars->map[vars->map_y][vars->map_x] == '1' ||
		vars->map[vars->map_y][vars->map_x] == 'C')
		vars->m_count = 0;
	else if (vars->map[vars->map_y][vars->map_x] == 'P')
		vars->p_check += 1;
	else if (vars->map[vars->map_y][vars->map_x] == 'E')
		vars->exit_check += 1;
	else if (vars->map[vars->map_y][vars->map_x] == 'H')
		vars->h_check += 1;
	else if (vars->map[vars->map_y][vars->map_x] == 'V')
		vars->v_check += 1;
	else
		terminate(vars, "Error\nInvalid map character.");
}

void	check_mapsize_chars(t_vars *vars)
{
	while (vars->map[vars->map_y])
	{
		vars->map_x = 0;
		while (vars->map[vars->map_y][vars->map_x])
		{
			check_map_helper(vars);
			vars->map_x++;
		}
		vars->map_y++;
	}
	if (vars->p_check != 1)
		terminate(vars, "Error\nPlayer not found or has duplicate.");
	if (vars->exit_check != 1)
		terminate(vars, "Error\nExit not found or has duplicate.");
	if (vars->v_check > 1 || vars->h_check > 1)
		terminate(vars, "Error\nEnemy Horizontal/Vertical has duplicate.");
}

void	check_walls(t_vars *vars)
{
	int	error;

	error = 0;
	vars->yend = vars->map_y - 1;
	vars->xend = vars->map_x - 1;
	while (vars->map[vars->yy])
	{
		if (error > 0
			|| ft_strlen(vars->map[0]) != ft_strlen(vars->map[vars->yend]))
			terminate(vars, "Error\nWalls not surrounding map.");
		while (vars->map[vars->yy][vars->xx])
		{
			if (vars->map[0][vars->xx] != '1')
				error++;
			if (vars->map[vars->yend][vars->xx] != '1')
				error++;
			vars->xx++;
		}
		if (vars->map[vars->yy][0] != '1')
			error++;
		if (vars->map[vars->yy][vars->xend] != '1')
			error++;
		vars->yy++;
	}
}

void	flood(int y, int x, t_vars *vars)
{
	if (vars->flood[y][x] == '0'
		|| vars->flood[y][x] == 'C'
		|| vars->flood[y][x] == 'P'
		|| vars->flood[y][x] == 'E')
	{
		vars->flood[y][x] = 'F';
		flood(y + 1, x, vars);
		flood(y - 1, x, vars);
		flood(y, x + 1, vars);
		flood(y, x - 1, vars);
	}
}

void	check_validpath(t_vars *vars)
{
	flood(vars->p_y, vars->p_x, vars);
	vars->xx = 0;
	vars->yy = 0;
	while (vars->flood[vars->yy])
	{
		while (vars->flood[vars->yy][vars->xx])
		{
			if (vars->flood[vars->yy][vars->xx] == 'C'
				|| vars->flood[vars->yy][vars->xx] == 'E')
				terminate(vars, "Error\nNo Valid Path to Exit");
			vars->xx++;
		}
		vars->xx = 0;
		vars->yy++;
	}
}
