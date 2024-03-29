/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:30:13 by prossi            #+#    #+#             */
/*   Updated: 2022/12/16 13:10:42 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	key_press(int keycode)
{
	if (keycode == ESC)
		quit_game();
	else if (keycode == W)
		data()->key.w = 1;
	else if (keycode == S)
		data()->key.s = 1;
	else if (keycode == A)
		data()->key.a = 1;
	else if (keycode == D)
		data()->key.d = 1;
	else if (keycode == LEFT)
		data()->key.left = 1;
	else if (keycode == RIGHT)
		data()->key.right = 1;
	return (0);
}

void	hooks(void)
{
	if (data()->key.w == 1)
		player_move_forward();
	if (data()->key.s == 1)
		player_move_backwards();
	if (data()->key.a == 1)
		player_move_left();
	if (data()->key.d == 1)
		player_move_right();
	if (data()->key.left == 1)
		player_rotate_left();
	if (data()->key.right == 1)
		player_rotate_right();
}
