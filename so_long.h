/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:15:29 by mliew             #+#    #+#             */
/*   Updated: 2022/08/17 21:50:50 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

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

	char	*p_path;
	void	*p_img;
	int		p_x;
	int		p_y;
	int		p_check;

	char	*bg_path;
	void	*bg_img;
	int		bg_x;
	int		bg_y;

	char	**map;
	int		mapx;
	int		mapy;

	char	*t_path;
	void	*t_img;
	int		treex;
	int		treey;
}	t_vars;

int		putimg(t_vars *vars);
int		putplayer(t_vars *vars);
int		putbg(t_vars *vars);
int		puttree(t_vars *vars);
void	check_map(t_vars *vars);
void	initialize_vars(t_vars *vars);

#endif