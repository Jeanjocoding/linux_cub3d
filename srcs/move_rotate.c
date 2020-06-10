/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:56:48 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:56:50 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

extern int	**g_worldmap;
extern int	g_screenheight;
extern int	g_screenwidth;
int			g_keytab[100000];

int	apply_command(t_vars *vars)
{
	if (g_keytab[KEY_UP] == 1)
		move_forward(&(vars->fov));
	if (g_keytab[KEY_DOWN] == 1)
		move_backward(&(vars->fov));
	if (g_keytab[KEY_RIGHT] == 1)
		move_right(&(vars->fov));
	if (g_keytab[KEY_LEFT] == 1)
		move_left(&(vars->fov));
	if (g_keytab[KEY_ARROW_LEFT] == 1)
		rotate_left(&(vars->fov));
	if (g_keytab[KEY_ARROW_RIGHT] == 1)
		rotate_right(&(vars->fov));
	if (g_keytab[KEY_ESCAPE] == 1)
		close_window(vars);
	generate_image(vars, &vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	get_command(int keycode, t_vars *vars)
{
	g_keytab[keycode] = 1;
	apply_command(vars);
	return (0);
}

int	release_command(int keycode, t_vars *vars)
{
	g_keytab[keycode] = 0;
	apply_command(vars);
	return (0);
}
