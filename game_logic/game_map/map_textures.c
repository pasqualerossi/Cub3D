/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:21:50 by prossi            #+#    #+#             */
/*   Updated: 2022/12/07 19:54:57 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	textures(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (ft_array_length(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "NO", 3) == 0)
		data()->xpm[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 3) == 0)
		data()->xpm[1] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 3) == 0)
		data()->xpm[2] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 3) == 0)
		data()->xpm[3] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 2) \
		&& ft_strncmp(tokens[0], "F", 2))
		return (1);
	ft_free(&tokens);
	return (0);
}

static int	rgb(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (ft_array_length(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "F", 1) == 0)
		data()->rgb[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 1) == 0)
		data()->rgb[1] = ft_strdup(tokens[1]);
	ft_free(&tokens);
	return (0);
}

int	parse_info(int fd)
{
	char	*line;
	int		ret;

	data()->xpm = ft_calloc(sizeof(char *) , 5);
	if (!data()->xpm)
		return (1);
	data()->rgb = ft_calloc(sizeof(char *) , 3);
	if (!data()->rgb)
		return (1);
	while (ft_array_length(data()->xpm) != 4 \
		|| ft_array_length(data()->rgb) != 2)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		if (ft_strlen(line) == 0)
			;
		else if (textures(line) == 1 || rgb(line) == 1)
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

void	fill_texture_array(int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data()->img2[i].height)
	{
		x = -1;
		while (++x < data()->img2[i].width)
		{
			data()->texture[i][data()->img2[i].height * y + x] = \
				(data()->img2[i].addr[data()->img2[i].height * y + x]);
		}
	}
}

int	init_textures(void)
{
	int		i;
	void	*tmp;
	int		*addr;

	i = 0;
	while (i < 4)
	{
		tmp = mlx_xpm_file_to_image(data()->mlx, data()->xpm[i], \
			&(data()->img2[i].width), &(data()->img2[i].height));
		data()->img2[i].ptr_img = tmp;
		if (!data()->img2[i].ptr_img)
			return (1);
		addr = (int *) mlx_get_data_addr(data()->img2[i].ptr_img, \
			&data()->img2[i].bits_per_pixel, &data()->img2[i].line_len, \
			&data()->img2[i].endian);
		data()->img2[i].addr = addr;
		if (!data()->img2[i].addr)
			return (1);
		fill_texture_array(i);
		mlx_destroy_image(data()->mlx, data()->img2[i].ptr_img);
		i++;
	}
	return (0);
}
