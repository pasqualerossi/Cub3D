/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_raycasting_calucations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:58:32 by prossi            #+#    #+#             */
/*   Updated: 2022/12/07 19:31:03 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_ray_position_and_direction(int x)
{
	data()->var.camera_x = 2 * x / (double) SCREEN_WIDTH - 1;
	data()->var.ray_direction_x = data()->var.direction_x + \
							data()->var.plane_x * data()->var.camera_x;
	data()->var.ray_direction_y = data()->var.direction_y + \
							data()->var.plane_y * data()->var.camera_x;
}

void	set_box_position(void)
{
	data()->var.map_x = (int) data()->var.position_x;
	data()->var.map_y = (int) data()->var.position_y;
	data()->var.hit = 0;
}

void	calculate_delta_distance(void)
{
	if (data()->var.ray_direction_x == 0)
		data()->var.delta_distance_x = 1e30;
	else
		data()->var.delta_distance_x = fabs(1 / data()->var.ray_direction_x);
	if (data()->var.ray_direction_y == 0)
		data()->var.delta_distance_y = 1e30;
	else
		data()->var.delta_distance_y = fabs(1 / data()->var.ray_direction_y);
}

void	calculate_step_and_side_distance_x(void)
{
	if (data()->var.ray_direction_x < 0)
	{
		data()->var.step_x = -1;
		data()->var.side_distance_x = (data()->var.position_x
			- data()->var.map_x) \
								* data()->var.delta_distance_x;
	}
	else
	{
		data()->var.step_x = 1;
		data()->var.side_distance_x = (data()->var.map_x + 1.0 \
			- data()->var.position_x) * data()->var.delta_distance_x;
	}
}

void	calculate_step_and_side_distance_y(void)
{
	if (data()->var.ray_direction_y < 0)
	{
		data()->var.step_y = -1;
		data()->var.side_distance_y = (data()->var.position_y
			- data()->var.map_y) \
								* data()->var.delta_distance_y;
	}
	else
	{
		data()->var.step_y = 1;
		data()->var.side_distance_y = (data()->var.map_y + 1.0 \
			- data()->var.position_y) * data()->var.delta_distance_y;
	}
}
