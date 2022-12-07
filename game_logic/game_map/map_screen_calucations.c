/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_screen_calucations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:02:18 by prossi            #+#    #+#             */
/*   Updated: 2022/12/07 18:17:23 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_distance_perspective(void)
{
	if (data()->var.side == 0)
		data()->var.perspective_wall_distance = \
			data()->var.side_distance_x - data()->var.delta_distance_x;
	else
		data()->var.perspective_wall_distance = \
			data()->var.side_distance_y - data()->var.delta_distance_y;
}

void	calculate_vertical_line_height(void)
{
	data()->var.line_height = \
		(int)(SCREEN_HEIGHT / data()->var.perspective_wall_distance);
}

void	calculate_draw_start_and_draw_end(void)
{
	int	draw_start;

	draw_start = (-1) * data()->var.line_height / 2 + SCREEN_HEIGHT / 2;
	data()->var.draw_start = draw_start;
	if (data()->var.draw_start < 0)
		data()->var.draw_start = 0;
	data()->var.draw_end = data()->var.line_height / 2 + SCREEN_HEIGHT / 2;
	if (data()->var.draw_end >= SCREEN_HEIGHT)
		data()->var.draw_end = SCREEN_HEIGHT - 1;
}
