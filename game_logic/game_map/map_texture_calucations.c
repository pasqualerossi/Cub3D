/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture_calucations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:54:34 by prossi            #+#    #+#             */
/*   Updated: 2022/12/07 19:47:57 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_texture_x(void)
{
	if (data()->var.side == 0)
		data()->var.wall_x = data()->var.position_y + \
			data()->var.perspective_wall_distance * data()->var.ray_direction_y;
	else
		data()->var.wall_x = data()->var.position_x + \
			data()->var.perspective_wall_distance * data()->var.ray_direction_x;
	data()->var.wall_x -= floor(data()->var.wall_x);
	data()->var.texture_x = (int)(data()->var.wall_x * (double)TEXTURE_WIDTH);
	if (data()->var.side == 0 && data()->var.ray_direction_x > 0)
		data()->var.texture_x = TEXTURE_WIDTH - data()->var.texture_x - 1;
	if (data()->var.side == 1 && data()->var.ray_direction_y < 0)
		data()->var.texture_x = TEXTURE_WIDTH - data()->var.texture_x - 1;
}

void	draw_vertical_texture_stripe(int x)
{
	double	step;
	double	texture_position;
	int		y;

	step = 1.0 * TEXTURE_HEIGHT / data()->var.line_height;
	texture_position = (data()->var.draw_start - SCREEN_HEIGHT / 2 \
		+ data()->var.line_height / 2) * step;
	y = data()->var.draw_start;
	while (y < data()->var.draw_end)
	{
		data()->var.texture_y = (int) texture_position & (TEXTURE_HEIGHT - 1);
		texture_position += step;
		data()->var.color = data()->texture[data()->var.texture_number][
		TEXTURE_HEIGHT * data()->var.texture_y + data()->var.texture_x];
		if (data()->var.side == 1)
			data()->var.color = (data()->var.color >> 1) & 8355711;
		mlx_place_pixel(x, y, data()->var.color);
		y++;
	}
}
