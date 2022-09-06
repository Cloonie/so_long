/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:00:22 by mliew             #+#    #+#             */
/*   Updated: 2022/09/06 21:27:42 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movementcountbar(t_vars *vars)
{
	while (vars->bar <= vars->map_x)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bar_img,
			vars->bar++ *64, vars->map_y * 64);
	vars->bar = 0;
	mlx_string_put(vars->mlx, vars->win, 25, vars->map_y * 64 + 15, 0,
		ft_strjoin("Movement Count: ", ft_itoa(vars->m_count)));
}

void	exit_condition(t_vars *vars)
{
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
}

int	terminate(t_vars *vars, char *msg)
{
	int	i;

	i = 0;
	(void)vars;
	if (msg)
		ft_printf("%s\n", msg);
	while (vars->map[i])
		free(vars->map[i++]);
	free(vars->map);
	// system("leaks so_long");
	exit (0);
}
