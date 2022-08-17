/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:16:45 by mliew             #+#    #+#             */
/*   Updated: 2022/08/17 22:06:02 by mliew            ###   ########.fr       */
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

int	closewin(t_vars *vars)
{
	(void)vars;
	system("leaks so_long");
	exit (0);
}

void	read_map(char *av, t_vars *vars)
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

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		initialize_vars(&vars);
		read_map(av[1], &vars);
		check_map(&vars);
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
