/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:15:29 by mliew             #+#    #+#             */
/*   Updated: 2022/08/23 17:32:41 by mliew            ###   ########.fr       */
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
// mlx
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;

// map
	char	**map;
	int		map_x;
	int		map_y;

// player
	char	*path;
	void	*pu_img;
	void	*pd_img;;
	void	*pl_img;;
	void	*pr_img;
	int		p_x;
	int		p_y;
	int		p_check;
	int		m_count;

// background
	char	*bg_path;
	void	*bg_img;
	int		bg_x;
	int		bg_y;

// wall
	char	*wall_path;
	void	*wall_img;

// collectables
	char	*col_path;
	void	*col_img;
	int		col_count;
	int		col_collect;

// exit
	char	*exit_path;
	void	*exit_img;
	int		exit_x;
	int		exit_y;

}	t_vars;

void	initialize_vars(t_vars *vars);
void	malloc_mapsize(char *av, t_vars *vars);
void	check_mapsize_chars(t_vars *vars);
void	putbg(t_vars *vars);
void	putstaticimg(t_vars *vars);
int		putexit(t_vars *vars);
int		terminate(t_vars *vars, char *msg);
void	init_col(t_vars *vars, int x, int y);

// int		putplayer(t_vars *vars);
#endif