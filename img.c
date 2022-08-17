/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:49:13 by mliew             #+#    #+#             */
/*   Updated: 2022/08/17 22:09:31 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_vars *vars)
{
	while (vars->map[vars->mapy])
	{
		vars->mapx = 0;
		while (vars->map[vars->mapy][vars->mapx])
		{
			if (vars->map[vars->mapy][vars->mapx] == '0')
				++vars->mapx;
			else if (vars->map[vars->mapy][vars->mapx] == '1')
			{
				vars->treex = vars->mapx;
				vars->treey = vars->mapy;
				vars->mapx++;
			}
			// else if (map[vars->mapy][vars->mapx] == 'C')
			// else if (map[vars->mapy][vars->mapx] == 'E')
			else if (vars->map[vars->mapy][vars->mapx] == 'P' && vars->p_check == 0)
			{
				vars->p_x = vars->mapx;
				vars->p_y = vars->mapy;
				++vars->mapx;
				++vars->p_check;
			}
			else
			{
				write(1, "Error invalid character.", 24);
				exit (0);
			}
		}
		free(vars->map[vars->mapy]);
		++vars->mapy;
	}
	free(vars->map);
}

int	putimg(t_vars *vars)
{
	putbg(vars);
	putplayer(vars);
	puttree(vars);
	return (0);
}

int	putbg(t_vars *vars)
{
	vars->bg_x = 0;
	vars->bg_path = "sprites/background.xpm";
	
	vars->bg_img = mlx_xpm_file_to_image(vars->mlx, vars->bg_path, &vars->img_width, &vars->img_height);
	while (vars->bg_x < vars->mapx * 64)
	{
		vars->bg_y = 0;
		while (vars->bg_y < vars->mapy * 64)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img, vars->bg_x, vars->bg_y);
			vars->bg_y += 64;
		}
		vars->bg_x += 64;
	}
	return (0);
}

int	putplayer(t_vars *vars)
{
	vars->p_path = "sprites/pikachu.xpm";
	vars->p_img = mlx_xpm_file_to_image(vars->mlx, vars->p_path, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->p_img, vars->p_x*64, vars->p_y*64);
	return (0);
}

int	puttree(t_vars *vars)
{
	vars->t_path = "sprites/tree.xpm";
	vars->t_img = mlx_xpm_file_to_image(vars->mlx, vars->t_path, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->t_img, vars->treex * 64, vars->treey * 64);
	return (0);
}