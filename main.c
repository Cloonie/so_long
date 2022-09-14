/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:16:45 by mliew             #+#    #+#             */
/*   Updated: 2022/09/14 20:51:51 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_helper(int key, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img,
		vars->p_x * 64, vars->p_y * 64);
	if (key == W)
	{
		--vars->p_y;
		vars->current_img = vars->p_img.up.one;
	}
	if (key == A)
	{
		--vars->p_x;
		vars->current_img = vars->p_img.left.one;
	}
	if (key == S)
	{
		++vars->p_y;
		vars->current_img = vars->p_img.down.one;
	}
	if (key == D)
	{	
		++vars->p_x;
		vars->current_img = vars->p_img.right.one;
	}
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

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd <= 0)
		exit_nofree("Error\nInvalid map file.");
	if (!ft_strnstr(av, ".ber", ft_strlen(av)))
		exit_nofree("Error\nMap file no '.ber'.");
	if (ft_strncmp((ft_strnstr(av, ".ber", ft_strlen(av))),
			".ber", ft_strlen(av)))
		exit_nofree("Error\nMap file type not '.ber'.");
	buf = malloc(sizeof(char) * RAM);
	i = read(fd, buf, RAM);
	buf[i] = '\0';
	if (!buf[0])
		exit_nofree("Error\nMap empty.");
	if (buf[0] == '\n' || buf[i - 1] == '\n' || ft_strnstr(buf, "\n\n", 1000))
		exit_nofree("Error\nMap not rectangular.");
	vars->map = ft_split(buf, '\n');
	vars->flood = ft_split(buf, '\n');
	if (vars->map[0][0] == '\n')
		exit(0);
	free(buf);
}

int	loop_hook(t_vars *vars)
{
	print_imgs(vars);
	movementcountbar(vars);
	animation(vars);
	exit_condition(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		init_vars(&vars);
		malloc_map(av[1], &vars);
		check_mapsize_chars(&vars);
		vars.win = mlx_new_window(vars.mlx, vars.map_x * 64,
				vars.map_y * 64 + 50, "so_long");
		check_walls(&vars);
		allocate_pos(&vars);
		check_validpath(&vars);
		mlx_loop_hook(vars.mlx, loop_hook, &vars);
		mlx_key_hook(vars.win, key_loop, &vars);
		mlx_hook(vars.win, 17, 0, terminate, &vars);
		mlx_loop(vars.mlx);
	}
	else
		write(1, "Error\n./so_long [MAP]", 22);
}
