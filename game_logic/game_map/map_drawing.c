/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:12:06 by prossi            #+#    #+#             */
/*   Updated: 2022/12/13 11:52:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mlx_place_pixel(int x, int y, int colour)
{
	char	*distance;

	distance = data()->img.address + \
		(y * data()->img.line_length + x * (data()->img.bits_per_pixel / 8));
	*(unsigned int *)distance = colour;
}

void	draw_vertical_line(int x)
{
	int	y;

	y = data()->var.draw_start;
	while (y < data()->var.draw_end)
	{
		mlx_place_pixel(x, y, data()->var.color);
		y++;
	}
}

void	draw_floor(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT / 2 - 1;
		while (++j < SCREEN_HEIGHT)
			mlx_place_pixel(i, j, data()->floor);
		i++;
	}
}

void	draw_ceiling(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT / 2)
			mlx_place_pixel(i, j, data()->ceilling);
		i++;
	}
}
