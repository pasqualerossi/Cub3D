/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:37:56 by prossi            #+#    #+#             */
/*   Updated: 2022/12/07 19:07:32 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_right(void)
{
	double	old_direction_x;
	double	old_plane_x;

	old_direction_x = data()->var.direction_x;
	data()->var.direction_x = data()->var.direction_x
	* cos(data()->var.rotate_speed) \
		- data()->var.direction_y * sin(data()->var.rotate_speed);
	data()->var.direction_y = old_direction_x * sin(data()->var.rotate_speed) \
		+ data()->var.direction_y * cos(data()->var.rotate_speed);
	old_plane_x = data()->var.plane_x;
	data()->var.plane_x = data()->var.plane_x * cos(data()->var.rotate_speed) \
		- data()->var.plane_y * sin(data()->var.rotate_speed);
	data()->var.plane_y = old_plane_x * sin(data()->var.rotate_speed) \
		+ data()->var.plane_y * cos(data()->var.rotate_speed);
}

void	rotate_left(void)
{
	double	old_direction_x;
	double	old_plane_x;

	old_direction_x = data()->var.direction_x;
	data()->var.direction_x = data()->var.direction_x
	* cos(-data()->var.rotate_speed) \
		- data()->var.direction_y * sin(-data()->var.rotate_speed);
	data()->var.direction_y = old_direction_x * sin(-data()->var.rotate_speed) \
		+ data()->var.direction_y * cos(-data()->var.rotate_speed);
	old_plane_x = data()->var.plane_x;
	data()->var.plane_x = data()->var.plane_x * cos(-data()->var.rotate_speed) \
		- data()->var.plane_y * sin(-data()->var.rotate_speed);
	data()->var.plane_y = old_plane_x * sin(-data()->var.rotate_speed) \
		+ data()->var.plane_y * cos(-data()->var.rotate_speed);
}
