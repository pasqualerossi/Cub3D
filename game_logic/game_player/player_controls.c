/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:30:13 by prossi            #+#    #+#             */
/*   Updated: 2022/12/07 18:16:46 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	else if (keycode == P)
		data()->key.p = !data()->key.p;
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == W)
		data()->key.w = 0;
	else if (keycode == S)
		data()->key.s = 0;
	else if (keycode == A)
		data()->key.a = 0;
	else if (keycode == D)
		data()->key.d = 0;
	else if (keycode == LEFT)
		data()->key.left = 0;
	else if (keycode == RIGHT)
		data()->key.right = 0;
	return (0);
}

void	hooks(void)
{
	if (data()->key.w == 1)
		move_forward();
	if (data()->key.s == 1)
		move_backwards();
	if (data()->key.a == 1)
		move_left();
	if (data()->key.d == 1)
		move_right();
	if (data()->key.left == 1)
		rotate_left();
	if (data()->key.right == 1)
		rotate_right();
}
