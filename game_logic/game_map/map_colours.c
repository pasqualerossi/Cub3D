/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:49:48 by prossi            #+#    #+#             */
/*   Updated: 2022/12/08 14:34:27 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	*validate_rgb(char **array)
{
	int	i;
	int	*rgb;

	i = 0;
	rgb = malloc(sizeof(int) * 4);
	if (!rgb)
		return (NULL);
	while (array[i])
	{
		rgb[i] = ft_atoi(array[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (NULL);
		i++;
	}
	rgb[i] = 0;
	return (rgb);
}

void	convert_colors(int *rgb, int i)
{
	unsigned long	temporary;

	if (i == 0)
	{
		temporary = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		data()->floor = temporary;
	}
	if (i == 1)
	{
		temporary = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		data()->ceilling = temporary;
	}
}

int	init_colours(void)
{
	int				i;
	char			**temporary;
	int				*rgb;

	i = 0;
	while (data()->rgb[i])
	{
		temporary = ft_split(data()->rgb[i], ',');
		if (!temporary)
			return (1);
		rgb = validate_rgb(temporary);
		if (!rgb)
		{
			free(rgb);
			return (1);
		}
		convert_colors(rgb, i);
		ft_free(&temporary);
		free(rgb);
		i++;
	}
	return (0);
}
