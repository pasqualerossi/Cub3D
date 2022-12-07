/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:24:57 by prossi            #+#    #+#             */
/*   Updated: 2022/12/07 19:20:00 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_texture(void)
{
	if (data()->var.side == 0)
	{
		if (data()->var.map_x > data()->var.position_x)
			data()->var.texture_number = 1;
		else
			data()->var.texture_number = 3;
	}
	else
	{
		if (data()->var.map_y > data()->var.position_y)
			data()->var.texture_number = 2;
		else
			data()->var.texture_number = 0;
	}
}

void	dda(void)
{
	while (data()->var.hit == 0)
	{
		if (data()->var.side_distance_x < data()->var.side_distance_y)
		{
			data()->var.side_distance_x += data()->var.delta_distance_x;
			data()->var.map_x += data()->var.step_x;
			data()->var.side = 0;
		}
		else
		{
			data()->var.side_distance_y += data()->var.delta_distance_y;
			data()->var.map_y += data()->var.step_y;
			data()->var.side = 1;
		}
		if (data()->map[data()->var.map_y][data()->var.map_x] == '1')
		{
			data()->var.hit = 1;
			set_texture();
		}
	}
}

void	raycast_loop(void)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		calculate_ray_position_and_direction(x);
		set_box_position();
		calculate_delta_distance();
		calculate_step_and_side_distance_x();
		calculate_step_and_side_distance_y();
		dda();
		calculate_distance_perspective();
		calculate_vertical_line_height();
		calculate_draw_start_and_draw_end();
		calculate_texture_x();
		draw_vertical_texture_stripe(x);
		x++;
	}
}
