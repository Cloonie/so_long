/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:15:29 by mliew             #+#    #+#             */
/*   Updated: 2022/08/19 19:46:39 by mliew            ###   ########.fr       */
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
	char	*p_path;
	void	*p_img;
	int		p_x;
	int		p_y;
	int		p_check;

// background
	char	*bg_path;
	void	*bg_img;
	int		bg_x;
	int		bg_y;

// wall
	char	*wall_path;
	void	*wall_img;
}	t_vars;

void	initialize_vars(t_vars *vars);
void	check_map(t_vars *vars);
int		putplayer(t_vars *vars);
void	putbg(t_vars *vars);
void	puttree(t_vars *vars);
int		terminate(t_vars *vars, char *msg);

#endif