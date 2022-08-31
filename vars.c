/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:27:38 by mliew             #+#    #+#             */
/*   Updated: 2022/08/31 16:23:11 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_vars *vars)
{
	vars->img_width = 64;
	vars->img_height = 64;
	vars->map_x = 0;
	vars->col_count = 0;
	vars->col_collect = 0;
	vars->xx = 0;
	vars->yy = 0;
	vars->p_check = 0;
	vars->exit_check = 0;
}

void	init_xpm(t_vars *vars)
{
	vars->bg_img = mlx_xpm_file_to_image(vars->mlx, "sprites/background.xpm",
			&vars->img_width, &vars->img_height);
	vars->psleep_img = mlx_xpm_file_to_image(vars->mlx, "sprites/psleep.xpm",
			&vars->img_width, &vars->img_height);
	// vars->pw_img = mlx_xpm_file_to_image(vars->mlx, "sprites/pikachuw.xpm",
	// 		&vars->img_width, &vars->img_height);
	// vars->pa_img = mlx_xpm_file_to_image(vars->mlx, "sprites/pikachua.xpm",
	// 		&vars->img_width, &vars->img_height);
	// vars->ps_img = mlx_xpm_file_to_image(vars->mlx, "sprites/pikachus.xpm",
	// 		&vars->img_width, &vars->img_height);
	// vars->pd_img = mlx_xpm_file_to_image(vars->mlx, "sprites/pikachud.xpm",
	// 		&vars->img_width, &vars->img_height);
	vars->wall_img = mlx_xpm_file_to_image(vars->mlx, "sprites/tree.xpm",
			&vars->img_width, &vars->img_height);
	vars->col_img = mlx_xpm_file_to_image(vars->mlx, "sprites/pokeball.xpm",
			&vars->img_width, &vars->img_height);
	vars->exit_img = mlx_xpm_file_to_image(vars->mlx, "sprites/exit.xpm",
			&vars->img_width, &vars->img_height);
	vars->bar_img = mlx_xpm_file_to_image(vars->mlx, "sprites/whitebg.xpm",
			&vars->img_width, &vars->img_height);
}
