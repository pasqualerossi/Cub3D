/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:37:56 by prossi            #+#    #+#             */
/*   Updated: 2022/10/28 15:38:08 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(void)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data()->var.dir_x;
	data()->var.dir_x = data()->var.dir_x * cos(data()->var.rot_speed) \
		- data()->var.dir_y * sin(data()->var.rot_speed);
	data()->var.dir_y = old_dir_x * sin(data()->var.rot_speed) \
		+ data()->var.dir_y * cos(data()->var.rot_speed);
	old_plane_x = data()->var.plane_x;
	data()->var.plane_x = data()->var.plane_x * cos(data()->var.rot_speed) \
		- data()->var.plane_y * sin(data()->var.rot_speed);
	data()->var.plane_y = old_plane_x * sin(data()->var.rot_speed) \
		+ data()->var.plane_y * cos(data()->var.rot_speed);
}

void	rotate_left(void)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data()->var.dir_x;
	data()->var.dir_x = data()->var.dir_x * cos(-data()->var.rot_speed) \
		- data()->var.dir_y * sin(-data()->var.rot_speed);
	data()->var.dir_y = old_dir_x * sin(-data()->var.rot_speed) \
		+ data()->var.dir_y * cos(-data()->var.rot_speed);
	old_plane_x = data()->var.plane_x;
	data()->var.plane_x = data()->var.plane_x * cos(-data()->var.rot_speed) \
		- data()->var.plane_y * sin(-data()->var.rot_speed);
	data()->var.plane_y = old_plane_x * sin(-data()->var.rot_speed) \
		+ data()->var.plane_y * cos(-data()->var.rot_speed);
}