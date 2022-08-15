/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:16:45 by mliew             #+#    #+#             */
/*   Updated: 2022/08/15 22:07:05 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_loop(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == A && vars->x != 0)
		vars->x -= 64;
	if (keycode == D && vars->x != 960)
		vars->x += 64;
	if (keycode == W && vars->y != 0)
		vars->y -= 64;
	if (keycode == S && vars->y != 960)
		vars->y += 64;
	return (0);
}

int	putimg(t_vars *vars)
{
	vars->bg_x = 0;
	vars->bg_y = 0;
	
	vars->bg_path = "sprites/background.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->bg_path, &vars->img_width, &vars->img_height);
	while (vars->bg_x < 1024)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->bg_x, vars->bg_y);
		while (vars->bg_y < 1024)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->bg_x, vars->bg_y);
			vars->bg_y += 64;
		}
		vars->bg_y = 0;
		vars->bg_x += 64;
	}
	
	vars->mc_path = "sprites/pikachu.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->mc_path, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
	return (0);
}

int	closewin(t_vars *vars)
{
	(void)vars;
	exit (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	char	*buf;
	char	**map;
	int		s_i = 0;
	int		c_i = 0;

	if (ac == 2)
	{
		vars.mapx = 0;
		vars.mapy = 0;
		
		int	fd = open(av[1], O_RDONLY);
		buf = malloc(sizeof(char) * 1000);
		int i = read(fd, buf, 1000);
		buf[i] = '\0';
		map = ft_split(buf, '\n');
		if (map[s_i][c_i])
		{
			while (map[s_i][c_i])
			{
				if (map[s_i][c_i] == '0')
					printf("mapx: %d\n", vars.mapx += 64);
				c_i++;
			}
			s_i++;
		}
		vars.img_width = 64;
		vars.img_height = 64;
		vars.x = 0;
		vars.y = 0;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 1024, 1024, "so_long");
		mlx_loop_hook(vars.mlx, putimg, &vars);
		mlx_key_hook(vars.win, key_loop, &vars);
		mlx_hook(vars.win, 17, 0, closewin, &vars);
		mlx_loop(vars.mlx);
	}
	else
		write(1, "Wrong number of arguments", 25);
}
