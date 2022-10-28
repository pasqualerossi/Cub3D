/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:26:38 by prossi            #+#    #+#             */
/*   Updated: 2022/10/28 12:28:18 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(void)
{
	int	y;
	int	x;

	y = (int)data()->var.pos_y;
	x = (int)(data()->var.pos_x + data()->var.dir_x * data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.pos_x += data()->var.dir_x * data()->var.move_speed;
	y = (int)(data()->var.pos_y + data()->var.dir_y * data()->var.move_speed);
	x = (int)data()->var.pos_x;
	if (data()->map[y][x] != '1')
		data()->var.pos_y += data()->var.dir_y * data()->var.move_speed;
}

void	move_backwards(void)
{
	int	y;
	int	x;

	y = (int)data()->var.pos_y;
	x = (int)(data()->var.pos_x - data()->var.dir_x * data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.pos_x -= data()->var.dir_x * data()->var.move_speed;
	y = (int)(data()->var.pos_y - data()->var.dir_y * data()->var.move_speed);
	x = (int)data()->var.pos_x;
	if (data()->map[y][x] != '1')
		data()->var.pos_y -= data()->var.dir_y * data()->var.move_speed;
}

void	move_left(void)
{
	int	y;
	int	x;

	y = (int)data()->var.pos_y;
	x = (int)(data()->var.pos_x + data()->var.dir_y * data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.pos_x += data()->var.dir_y * data()->var.move_speed;
	y = (int)(data()->var.pos_y - data()->var.dir_x * data()->var.move_speed);
	x = (int)data()->var.pos_x;
	if (data()->map[y][x] != '1')
		data()->var.pos_y -= data()->var.dir_x * data()->var.move_speed;
}

void	move_right(void)
{
	int	y;
	int	x;

	y = (int)data()->var.pos_y;
	x = (int)(data()->var.pos_x - data()->var.dir_y * data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.pos_x -= data()->var.dir_y * data()->var.move_speed;
	y = (int)(data()->var.pos_y + data()->var.dir_x * data()->var.move_speed);
	x = (int)data()->var.pos_x;
	if (data()->map[y][x] != '1')
		data()->var.pos_y += data()->var.dir_x * data()->var.move_speed;
}