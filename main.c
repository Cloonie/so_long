/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:16:45 by mliew             #+#    #+#             */
/*   Updated: 2022/08/23 17:18:35 by mliew            ###   ########.fr       */
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

int	key_loop(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		terminate(vars, "Program closed by ESC.");
	if (keycode == A && vars->map[vars->p_y][vars->p_x - 1] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img, vars->p_x * 64, vars->p_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->pl_img, --vars->p_x * 64, vars->p_y * 64);
		vars->m_count++;
	}
	else if (keycode == D && vars->map[vars->p_y][vars->p_x + 1] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img, vars->p_x * 64, vars->p_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->pr_img, ++vars->p_x * 64, vars->p_y * 64);
		vars->m_count++;
	}
	else if (keycode == W && vars->map[vars->p_y - 1][vars->p_x] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img, vars->p_x * 64, vars->p_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->pu_img, vars->p_x * 64, --vars->p_y * 64);
		vars->m_count++;
	}
	else if (keycode == S && vars->map[vars->p_y + 1][vars->p_x] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img, vars->p_x * 64, vars->p_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->pd_img, vars->p_x * 64, ++vars->p_y * 64);
		vars->m_count++;
	}
	if (vars->map[vars->p_y][vars->p_x] == 'C')
	{
		printf("colcollect:%d\n", vars->col_collect++);
		vars->map[vars->p_y][vars->p_x] = '0';
	}
	if (vars->map[vars->p_y][vars->p_x] == 'E' && vars->col_collect == vars->col_count)
		terminate(vars, "You WON!!!");
	return (0);
}

void	malloc_mapsize(char *av, t_vars *vars)
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
		vars.mlx = mlx_init();
		initialize_vars(&vars);
		malloc_mapsize(av[1], &vars);
		check_mapsize_chars(&vars);
		vars.win = mlx_new_window(vars.mlx, vars.map_x * 64,
				vars.map_y * 64, "so_long");
		mlx_loop_hook(vars.mlx, putexit, &vars);
		putbg(&vars);
		putstaticimg(&vars);
		mlx_key_hook(vars.win, key_loop, &vars);
		mlx_hook(vars.win, 17, 0, terminate, &vars);
		mlx_loop(vars.mlx);
	}
	else
		write(1, "!! ./so_long [MAP] !!", 21);
}