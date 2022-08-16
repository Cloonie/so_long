/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:16:45 by mliew             #+#    #+#             */
/*   Updated: 2022/08/16 21:50:53 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_loop(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		system("leaks so_long");
		exit(0);
	}
	if (keycode == A && vars->p_x != 0)
		vars->p_x -= 1;
	if (keycode == D && vars->p_x != vars->mapx - 1)
		vars->p_x += 1;
	if (keycode == W && vars->p_y != 0)
		vars->p_y -= 1;
	if (keycode == S && vars->p_y != vars->mapy - 1)
		vars->p_y += 1;
	return (0);
}

int	putimg(t_vars *vars)
{
	vars->bg_x = 0;
	vars->bg_y = 0;
	
	vars->path = "sprites/background.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_width, &vars->img_height);
	while (vars->bg_x < vars->mapx * 64)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->bg_x, vars->bg_y);
		while (vars->bg_y < vars->mapy * 64)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->bg_x, vars->bg_y);
			vars->bg_y += 64;
		}
		vars->bg_y = 0;
		vars->bg_x += 64;
	}

	vars->path = "sprites/pikachu.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->p_x * 64, vars->p_y * 64);

	vars->path = "sprites/tree.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->treex, vars->treey);
	return (0);
}

int	closewin(t_vars *vars)
{
	(void)vars;
	system("leaks so_long");
	exit (0);
}

void	read_map(char *av, t_vars *vars)
{	
	char	*buf;
	char	**map;

	int	fd = open(av, O_RDONLY);
	buf = malloc(sizeof(char) * 1000);
	int i = read(fd, buf, 1000);
	buf[i] = '\0';
	map = ft_split(buf, '\n');
	free(buf);

	vars->treex = 0;
	vars->treey = 0;
	vars->mapy = 0;
	while (map[vars->mapy])
	{
		vars->mapx = 0;
		while (map[vars->mapy][vars->mapx])
		{
			if (map[vars->mapy][vars->mapx] == '0')
				++vars->mapx;
			else if (map[vars->mapy][vars->mapx++] == '1')
			{
				++vars->treex
			}
			// else if (map[vars->mapy][vars->mapx] == 'C')
			// else if (map[vars->mapy][vars->mapx] == 'E')
			else if (map[vars->mapy][vars->mapx] == 'P')
			{
				vars->p_x = vars->mapx;
				vars->p_y = vars->mapy;
				++vars->mapx;
			}
			else
			{
				write(1, "Error invalid character.", 24);
				exit (0);
			}
		}
		free(map[vars->mapy]);
		++vars->mapy;
	}
	free(map);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		read_map(av[1], &vars);
		vars.img_width = 64;
		vars.img_height = 64;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, vars.mapx * 64, vars.mapy * 64, "so_long");
		mlx_loop_hook(vars.mlx, putimg, &vars);
		mlx_key_hook(vars.win, key_loop, &vars);
		mlx_hook(vars.win, 17, 0, closewin, &vars);
		mlx_loop(vars.mlx);
	}
	else
		write(1, "Wrong number of arguments", 25);
}
