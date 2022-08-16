/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:15:29 by mliew             #+#    #+#             */
/*   Updated: 2022/08/16 21:40:35 by mliew            ###   ########.fr       */
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
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
	int		p_x;
	int		p_y;
	int		bg_x;
	int		bg_y;
	int		mapx;
	int		mapy;
	int		treex;
	int		treey;
}	t_vars;

#endif