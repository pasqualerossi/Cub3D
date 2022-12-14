/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:39:39 by prossi            #+#    #+#             */
/*   Updated: 2022/12/14 15:50:34 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_array_length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

void	ft_free(char ***array)
{
	int	i;

	i = 0;
	if (!*array)
		return ;
	while ((*array)[i])
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

const char	*get_exit(const char *file)
{
	const char	*dot;

	dot = ft_strrchr(file, '.');
	if (!dot || dot == file)
		return ("");
	return (dot + 1);
}

unsigned long	rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}
