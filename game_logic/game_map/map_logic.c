/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:20:09 by prossi            #+#    #+#             */
/*   Updated: 2022/12/07 19:12:31 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_exit_init(char *s)
{
	write(2, s, ft_strlen(s));
	ft_free(&data()->xpm);
	ft_free(&data()->rgb);
	ft_free(&data()->map);
	exit(1);
}

static int	map(char *line)
{
	char	**tmp;

	if (!data()->map)
	{
		data()->map = malloc(sizeof(char *) * 2);
		if (!data()->map)
			return (1);
		data()->map[0] = ft_strdup(line);
		data()->map[1] = NULL;
	}
	else
	{
		tmp = ft_reallocation(data()->map, ft_array_length(data()->map) + 2);
		if (!tmp)
			return (1);
		data()->map = tmp;
		data()->map[ft_array_length(data()->map)] = ft_strdup(line);
	}
	return (0);
}

void	init(void)
{
	void	*tmp;

	data()->mlx = mlx_init();
	if (init_textures() == 1)
		ft_exit_init("Error\nCannot load textures\n");
	if (init_colours() == 1)
		ft_exit_init("Error\nCannot load colors\n");
	if (validate_map() == 1)
		ft_exit_init("Error\nInvalid map\n");
	tmp = mlx_new_window(data()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	data()->win = tmp;
}

int	parse_map(int fd)
{
	char	*line;
	int		ret;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		if (ft_strlen(line) == 0 && !data()->map)
			;
		else if (map(line) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
		if (ret == 0)
			break ;
	}
	return (0);
}
