/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:26:38 by prossi            #+#    #+#             */
/*   Updated: 2022/12/12 13:40:39 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_move_forward(void)
{
	int	y;
	int	x;

	y = (int)data()->var.position_y;
	x = (int)(data()->var.position_x + data()->var.direction_x
			* data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.position_x += data()->var.direction_x
		* data()->var.move_speed;
	y = (int)(data()->var.position_y + data()->var.direction_y
			* data()->var.move_speed);
	x = (int)data()->var.position_x;
	if (data()->map[y][x] != '1')
		data()->var.position_y += data()->var.direction_y
		* data()->var.move_speed;
}

void	player_move_backwards(void)
{
	int	y;
	int	x;

	y = (int)data()->var.position_y;
	x = (int)(data()->var.position_x - data()->var.direction_x
			* data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.position_x -= data()->var.direction_x
		* data()->var.move_speed;
	y = (int)(data()->var.position_y - data()->var.direction_y
			* data()->var.move_speed);
	x = (int)data()->var.position_x;
	if (data()->map[y][x] != '1')
		data()->var.position_y -= data()->var.direction_y
		* data()->var.move_speed;
}

void	player_move_left(void)
{
	int	y;
	int	x;

	y = (int)data()->var.position_y;
	x = (int)(data()->var.position_x + data()->var.direction_y
			* data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.position_x += data()->var.direction_y
		* data()->var.move_speed;
	y = (int)(data()->var.position_y - data()->var.direction_x
			* data()->var.move_speed);
	x = (int)data()->var.position_x;
	if (data()->map[y][x] != '1')
		data()->var.position_y -= data()->var.direction_x
		* data()->var.move_speed;
}

void	player_move_right(void)
{
	int	y;
	int	x;

	y = (int)data()->var.position_y;
	x = (int)(data()->var.position_x - data()->var.direction_y
			* data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.position_x -= data()->var.direction_y
		* data()->var.move_speed;
	y = (int)(data()->var.position_y + data()->var.direction_x
			* data()->var.move_speed);
	x = (int)data()->var.position_x;
	if (data()->map[y][x] != '1')
		data()->var.position_y += data()->var.direction_x
		* data()->var.move_speed;
}

void	player_rotate_right(void)
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

void	player_rotate_left(void)
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
