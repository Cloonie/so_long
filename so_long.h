/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:15:29 by mliew             #+#    #+#             */
/*   Updated: 2022/08/25 15:52:49 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	int		xx;
	int		yy;

	char	**map;
	int		map_x;
	int		map_y;

	void	*pu_img;
	void	*pd_img;
	void	*pl_img;
	void	*pr_img;
	int		p_x;
	int		p_y;
	int		m_count;

	void	*bg_img;
	int		bg_x;
	int		bg_y;

	void	*wall_img;

	void	*col_img;
	int		col_count;
	int		col_collect;

	void	*exit_img;
	int		exit_x;
	int		exit_y;
}	t_vars;

void	init_vars(t_vars *vars);
void	init_xpm(t_vars *vars);
void	malloc_map(char *av, t_vars *vars);
void	check_mapsize_chars(t_vars *vars);
void	check_walls(t_vars *vars);
void	print_bg(t_vars *vars);
void	print_staticimg(t_vars *vars);
void	key_helper(int key, t_vars *vars);
int		key_loop(int key, t_vars *vars);
int		exit_condition(t_vars *vars);
int		terminate(t_vars *vars, char *msg);

#endif