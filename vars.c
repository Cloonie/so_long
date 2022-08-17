/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:27:38 by mliew             #+#    #+#             */
/*   Updated: 2022/08/17 17:31:50 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_vars(t_vars *vars)
{
	vars->img_width = 64;
	vars->img_height = 64;

	vars->mapx = 0;
	vars->mapy = 0;

	vars->bg_x = 0;
	vars->bg_y = 0;

	vars->treex = 0;
	vars->treey = 0;

	vars->p_check = 0;
}