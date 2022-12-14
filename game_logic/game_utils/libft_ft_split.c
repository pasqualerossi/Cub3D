/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ft_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:06:40 by prossi            #+#    #+#             */
/*   Updated: 2022/12/14 15:51:39 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}

static int	ft_count(char const *s, char c)
{
	char	last;
	int		i;
	int		j;

	last = c;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (last == c && s[i] != c)
			j++;
		last = s[i];
		i++;
	}
	return (j);
}

static char	*create_substr(char *s, int *head, int c)
{
	int		tail;
	char	*substr;

	tail = *head;
	while (s[tail] != c && s[tail] != '\0')
		tail++;
	substr = ft_substr(s, *head, tail - *head);
	*head = tail;
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	int		head;
	int		i;
	int		tail;
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!arr)
		return (NULL);
	head = 0;
	tail = 0;
	i = 0;
	while (s[head] != '\0')
	{
		if (s[head] != c)
			arr[i++] = create_substr((char *)s, &head, c);
		else
			head++;
	}
	arr[i] = NULL;
	return (arr);
}
