/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:45:48 by prossi            #+#    #+#             */
/*   Updated: 2022/12/08 14:29:38 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_side_distance(t_ray *ray, t_point pos)
{
	if (ray->ray_dir.x < 0)
		ray->side_dist.x = (pos.x - (double)ray->map_x) * ray->delta_dist.x;
	else
		ray->side_dist.x = (ray->map_x + 1.0 - pos.x) * ray->delta_dist.x;
	if (ray->ray_dir.y < 0)
		ray->side_dist.y = (pos.y - (double)ray->map_y) * ray->delta_dist.y;
	else
		ray->side_dist.y = (ray->map_y + 1.0 - pos.y) * ray->delta_dist.y;
}

static void	set_step(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir.y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

static void	set_delta_distance(t_ray *ray)
{
	if (ray->ray_dir.y == 0)
	{
		ray->delta_dist.x = 0;
	}
	else
	{
		if (ray->ray_dir.x == 0)
			ray->delta_dist.x = 1;
		else
			ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	}
	if (ray->ray_dir.x == 0)
	{
		ray->delta_dist.y = 0;
	}
	else
	{
		if (ray->ray_dir.y == 0)
			ray->delta_dist.y = 1;
		else
			ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	}
}

void	set_ray(t_state *state, t_ray *ray, double camera_x)
{
	ray->ray_dir.x = state->dir.x + state->plane.x * camera_x;
	ray->ray_dir.y = state->dir.y + state->plane.y * camera_x;
	ray->map_x = (int)state->pos.x;
	ray->map_y = (int)state->pos.y;
	set_delta_distance(ray);
	set_step(ray);
	set_side_distance(ray, state->pos);
}
