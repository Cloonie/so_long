/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:35:00 by mliew             #+#    #+#             */
/*   Updated: 2022/09/06 20:19:32 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ani_updown(t_vars *vars)
{
	if (vars->current_img == vars->p_img.up.one
		|| vars->current_img == vars->p_img.up.two)
	{
		if (vars->frame == FRAMES)
			vars->current_img = vars->p_img.up.one;
		else if (vars->frame >= FRAMES * 2)
		{
			vars->current_img = vars->p_img.up.two;
			vars->frame = 0;
		}
	}
	if (vars->current_img == vars->p_img.down.one
		|| vars->current_img == vars->p_img.down.two)
	{
		if (vars->frame == FRAMES)
		vars->current_img = vars->p_img.down.one;
		else if (vars->frame >= FRAMES * 2)
		{
			vars->current_img = vars->p_img.down.two;
			vars->frame = 0;
		}
	}
}

void	ani_leftright(t_vars *vars)
{
	if (vars->current_img == vars->p_img.left.one
		|| vars->current_img == vars->p_img.left.two)
	{
		if (vars->frame == FRAMES)
			vars->current_img = vars->p_img.left.one;
		else if (vars->frame >= FRAMES * 2)
		{
			vars->current_img = vars->p_img.left.two;
			vars->frame = 0;
		}
	}
	if (vars->current_img == vars->p_img.right.one
		|| vars->current_img == vars->p_img.right.two)
	{
		if (vars->frame == FRAMES)
			vars->current_img = vars->p_img.right.one;
		else if (vars->frame >= FRAMES * 2)
		{
			vars->current_img = vars->p_img.right.two;
			vars->frame = 0;
		}
	}
}

void	ani_sleep(t_vars *vars)
{
	if (vars->frame == FRAMES)
		vars->current_img = vars->p_img.sleep.one;
	else if (vars->frame >= FRAMES * 2)
	{
		vars->current_img = vars->p_img.sleep.two;
		vars->frame = 0;
	}
}

void	player_animation(t_vars *vars)
{
	vars->frame++;
	if (vars->current_img == vars->p_img.sleep.one
		|| vars->current_img == vars->p_img.sleep.two)
		ani_sleep(vars);
	else
	{
		ani_updown(vars);
		ani_leftright(vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img,
		vars->p_x * 64, vars->p_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->current_img,
		vars->p_x * 64, vars->p_y * 64);
}
