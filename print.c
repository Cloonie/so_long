/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:59:41 by mliew             #+#    #+#             */
/*   Updated: 2022/09/06 22:09:02 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				vars->map[vars->yy][vars->xx] == 'H' ||
				vars->map[vars->yy][vars->xx] == 'V' ||
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
			}
			if (vars->map[vars->yy][vars->xx] == 'H')
			{
				vars->h_x = vars->xx;
				vars->h_y = vars->yy;
			}
			if (vars->map[vars->yy][vars->xx] == 'V')
			{
				vars->v_x = vars->xx;
				vars->v_y = vars->yy;
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
