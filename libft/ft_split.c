/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:19:04 by ktoraman          #+#    #+#             */
/*   Updated: 2024/11/01 19:50:41 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**free_all(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		k;
	char	**res;

	res = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!res || !s)
		return (NULL);
	k = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			res[k] = ft_substr(s, 0, i);
			if (res[k++] == NULL)
				return (free_all(res));
			s += i;
		}
	}
	res[k] = NULL;
	return (res);
}
