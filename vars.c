/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:27:38 by mliew             #+#    #+#             */
/*   Updated: 2022/09/13 16:18:43 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xpm1(t_vars *vars)
{
	vars->p_img.sleep.one = mlx_xpm_file_to_image(vars->mlx,
			"sprites/psleep.xpm", &vars->img_size, &vars->img_size);
	vars->p_img.up.one = mlx_xpm_file_to_image(vars->mlx,
			"sprites/pikachuw.xpm", &vars->img_size, &vars->img_size);
	vars->p_img.down.one = mlx_xpm_file_to_image(vars->mlx,
			"sprites/pikachus.xpm", &vars->img_size, &vars->img_size);
	vars->p_img.left.one = mlx_xpm_file_to_image(vars->mlx,
			"sprites/pikachua.xpm", &vars->img_size, &vars->img_size);
	vars->p_img.right.one = mlx_xpm_file_to_image(vars->mlx,
			"sprites/pikachud.xpm", &vars->img_size, &vars->img_size);
}

void	init_xpm2(t_vars *vars)
{
	vars->p_img.sleep.two = mlx_xpm_file_to_image(vars->mlx,
			"sprites/psleep2.xpm", &vars->img_size, &vars->img_size);
	vars->p_img.up.two = mlx_xpm_file_to_image(vars->mlx,
			"sprites/pikachuw2.xpm", &vars->img_size, &vars->img_size);
	vars->p_img.down.two = mlx_xpm_file_to_image(vars->mlx,
			"sprites/pikachus2.xpm", &vars->img_size, &vars->img_size);
	vars->p_img.left.two = mlx_xpm_file_to_image(vars->mlx,
			"sprites/pikachua2.xpm", &vars->img_size, &vars->img_size);
	vars->p_img.right.two = mlx_xpm_file_to_image(vars->mlx,
			"sprites/pikachud2.xpm", &vars->img_size, &vars->img_size);
}

void	init_xpm_others(t_vars *vars)
{
	vars->bg_img = mlx_xpm_file_to_image(vars->mlx, "sprites/background.xpm",
			&vars->img_size, &vars->img_size);
	vars->wall_img = mlx_xpm_file_to_image(vars->mlx, "sprites/tree.xpm",
			&vars->img_size, &vars->img_size);
	vars->col_img = mlx_xpm_file_to_image(vars->mlx, "sprites/pokeball.xpm",
			&vars->img_size, &vars->img_size);
	vars->exit_img = mlx_xpm_file_to_image(vars->mlx, "sprites/exit.xpm",
			&vars->img_size, &vars->img_size);
	vars->bar_img = mlx_xpm_file_to_image(vars->mlx, "sprites/whitebg.xpm",
			&vars->img_size, &vars->img_size);
	vars->enemy_img = mlx_xpm_file_to_image(vars->mlx, "sprites/enemy.xpm",
			&vars->img_size, &vars->img_size);
}

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	init_xpm1(vars);
	init_xpm2(vars);
	init_xpm_others(vars);
	vars->current_img = vars->p_img.sleep.one;
	vars->img_size = SIZE;
	vars->m_count = 0;
	vars->map_x = 0;
	vars->map_y = 0;
	vars->col_count = 0;
	vars->col_collect = 0;
	vars->xx = 0;
	vars->yy = 0;
	vars->h_x = 0;
	vars->h_y = 0;
	vars->v_x = 0;
	vars->v_y = 0;
	vars->p_check = 0;
	vars->exit_check = 0;
	vars->h_check = 0;
	vars->v_check = 0;
	vars->c_check = 0;
	vars->frame = FRAMES;
	vars->enemy_framev = 0;
	vars->enemy_frameh = 0;
}

void	exit_nofree(char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	exit (0);
}
