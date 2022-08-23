/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:27:38 by mliew             #+#    #+#             */
/*   Updated: 2022/08/23 17:31:04 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_vars(t_vars *vars)
{
// size of each image
	vars->img_width = 64;
	vars->img_height = 64;

// map size
	vars->map_x = 0;
	vars->map_y = 0;

// background
	vars->bg_path = "sprites/background.xpm";
	vars->bg_img = mlx_xpm_file_to_image(vars->mlx, vars->bg_path, &vars->img_width, &vars->img_height);
	vars->bg_x = 0;
	vars->bg_y = 0;

// player
	vars->path = "sprites/pikachu_up.xpm";
	vars->pu_img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_width, &vars->img_height);
	vars->path = "sprites/pikachu_down.xpm";
	vars->pd_img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_width, &vars->img_height);
	vars->path = "sprites/pikachu_left.xpm";
	vars->pl_img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_width, &vars->img_height);
	vars->path = "sprites/pikachu_right.xpm";
	vars->pr_img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_width, &vars->img_height);
	vars->p_x = 0;
	vars->m_count = 0;

// wall
	vars->wall_path = "sprites/tree.xpm";
	vars->wall_img = mlx_xpm_file_to_image(vars->mlx, vars->wall_path, &vars->img_width, &vars->img_height);

// collectables
	vars->col_path = "sprites/pokeball.xpm";
	vars->col_img = mlx_xpm_file_to_image(vars->mlx, vars->col_path, &vars->img_width, &vars->img_height);
	vars->col_count = 0;
	vars->col_collect = 0;

// exit
	vars->exit_path = "sprites/exit.xpm";
	vars->exit_img = mlx_xpm_file_to_image(vars->mlx, vars->exit_path, &vars->img_width, &vars->img_height);
	vars->exit_x = 0;

}