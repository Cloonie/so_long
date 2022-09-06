/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:15:29 by mliew             #+#    #+#             */
/*   Updated: 2022/09/06 22:09:10 by mliew            ###   ########.fr       */
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
# define SIZE 64
# define FRAMES 20

typedef struct player_animation {
	void	*one;
	void	*two;
}	t_animation;

typedef struct player_movement {
	t_animation	up;
	t_animation	down;
	t_animation	left;
	t_animation	right;
	t_animation	sleep;
}	t_move;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		img_size;

	int		xx;
	int		yy;
	int		xend;
	int		yend;

	int		bar;
	void	*bar_img;

	char	**map;
	int		map_x;
	int		map_y;

	t_move	p_img;
	void	*current_img;
	int		frame;
	int		p_x;
	int		p_y;
	int		p_check;
	int		m_count;

	void	*enemy_img;
	int		h_x;
	int		h_y;
	int		v_x;
	int		v_y;

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
	int		exit_check;
}	t_vars;

void	init_vars(t_vars *vars);
void	malloc_map(char *av, t_vars *vars);
void	check_mapsize_chars(t_vars *vars);
void	check_walls(t_vars *vars);
void	print_bgwall(t_vars *vars);
void	print_staticimg(t_vars *vars);

void	key_helper(int key, t_vars *vars);
int		key_loop(int key, t_vars *vars);

void	player_animation(t_vars *vars);
void	movementcountbar(t_vars *vars);
void	exit_condition(t_vars *vars);
int		terminate(t_vars *vars, char *msg);

#endif