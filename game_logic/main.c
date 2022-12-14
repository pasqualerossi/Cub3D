/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:59:16 by prossi            #+#    #+#             */
/*   Updated: 2022/12/14 15:57:06 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	launch_game(void)
{
	void	*img;
	char	*address;

	img = mlx_new_image(data()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data()->img.pointer_to_image = img;
	address = mlx_get_data_address(data()->img.pointer_to_image, \
		&data()->img.bits_per_pixel, &data()->img.line_length, \
		&data()->img.endian);
	data()->img.address = address;
	draw_floor();
	draw_ceiling();
	raycast_loop();
	hooks();
	data()->var.frame_time = 16 / 1000.0;
	data()->var.move_speed = data()->var.frame_time * 5.0;
	data()->var.rotate_speed = data()->var.frame_time * 3.0;
	mlx_put_image_to_window(data()->mlx, data()->win, \
		data()->img.pointer_to_image, 0, 0);
	mlx_destroy_image(data()->mlx, data()->img.pointer_to_image);
	return (0);
}

int	quit_game(void)
{
	mlx_destroy_window(data()->mlx, data()->win);
	exit(0);
	return (0);
}

t_cub	*data(void)
{
	static t_cub	data;

	return (&data);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\nMap not provided\n", 23);
		return (1);
	}
	parse(argv[1]);
	init();
	data()->key.p = 1;
	mlx_loop_hook(data()->mlx, launch_game, NULL);
	mlx_hook(data()->win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(data()->win, X_EVENT_KEY_RELEASE, 0, &key_release, NULL);
	mlx_hook(data()->win, X_EVENT_EXIT, 0, &quit_game, NULL);
	mlx_loop(data()->mlx);
	return (0);
}
