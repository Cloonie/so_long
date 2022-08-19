/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:27:38 by mliew             #+#    #+#             */
/*   Updated: 2022/08/19 19:47:12 by mliew            ###   ########.fr       */
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
	vars->p_path = "sprites/pikachu.xpm";
	vars->p_img = mlx_xpm_file_to_image(vars->mlx, vars->p_path, &vars->img_width, &vars->img_height);
	vars->p_check = 0;

// wall
	vars->wall_path = "sprites/tree.xpm";
	vars->wall_img = mlx_xpm_file_to_image(vars->mlx, vars->wall_path, &vars->img_width, &vars->img_height);
}