/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:16:45 by mliew             #+#    #+#             */
/*   Updated: 2022/08/31 22:31:34 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	key_helper(int key, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img,
		vars->p_x * 64, vars->p_y * 64);
	if (key == W)
	{
		vars->p_img = mlx_xpm_file_to_image(vars->mlx, "sprites/pikachuw.xpm",
				&vars->img_width, &vars->img_height);
		--vars->p_y;
	}
	if (key == A)
	{
		vars->p_img = mlx_xpm_file_to_image(vars->mlx, "sprites/pikachua.xpm",
				&vars->img_width, &vars->img_height);
		--vars->p_x;
	}
	if (key == S)
	{
		vars->p_img = mlx_xpm_file_to_image(vars->mlx, "sprites/pikachus.xpm",
				&vars->img_width, &vars->img_height);
		++vars->p_y;
	}
	if (key == D)
	{	
		vars->p_img = mlx_xpm_file_to_image(vars->mlx, "sprites/pikachud.xpm",
				&vars->img_width, &vars->img_height);
		++vars->p_x;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->p_img,
		vars->p_x * 64, vars->p_y * 64);
	// sleep(1);
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img,
	// 	vars->p_x * 64, vars->p_y * 64);
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->psleep_img,
	// 	vars->p_x * 64, vars->p_y * 64);
	ft_printf("Movement Count: %d\n", ++vars->m_count);
}

int	key_loop(int key, t_vars *vars)
{
	if (key == ESC)
		terminate(vars, "Program closed by ESC.");
	if (key == W && vars->map[vars->p_y - 1][vars->p_x] != '1')
		key_helper(key, vars);
	if (key == A && vars->map[vars->p_y][vars->p_x - 1] != '1')
		key_helper(key, vars);
	if (key == S && vars->map[vars->p_y + 1][vars->p_x] != '1')
		key_helper(key, vars);
	if (key == D && vars->map[vars->p_y][vars->p_x + 1] != '1')
		key_helper(key, vars);
	return (0);
}

void	malloc_map(char *av, t_vars *vars)
{	
	char	*buf;
	int		fd;
	int		i;

	fd = open(av, O_RDONLY);
	buf = malloc(sizeof(char) * 1000);
	i = read(fd, buf, 1000);
	buf[i] = '\0';
	vars->map = ft_split(buf, '\n');
	free(buf);
}

int	loop_hook(t_vars *vars)
{
	exit_condition(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		vars.mlx = mlx_init();
		init_vars(&vars);
		init_xpm(&vars);
		malloc_map(av[1], &vars);
		check_mapsize_chars(&vars);
		vars.win = mlx_new_window(vars.mlx, vars.map_x * 64,
				vars.map_y * 64 + 50, "so_long");
		check_walls(&vars);
		print_bgwall(&vars);
		print_staticimg(&vars);
		mlx_loop_hook(vars.mlx, loop_hook, &vars);
		mlx_key_hook(vars.win, key_loop, &vars);
		mlx_hook(vars.win, 17, 0, terminate, &vars);
		mlx_loop(vars.mlx);
	}
	else
		write(1, "Error\n./so_long [MAP]", 22);
}
