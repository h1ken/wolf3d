/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:52:52 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 16:52:23 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_nextwordl(char const *s, char c)
{
	size_t res;

	res = 0;
	while (s[res] && s[res] != c)
		res++;
	return (res);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t res;

	res = 0;
	while (*s)
		if (*s != c)
		{
			res++;
			s += ft_nextwordl(s, c);
		}
		else
			s++;
	return (res);
}

static char		**ft_freeprev(char ***what, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		free((*what)[i]);
		i++;
	}
	free(*what);
	*what = NULL;
	return (*what);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_countwords(s, c);
	if (!(res = (char **)ft_memalloc(sizeof(*res) * (words + 1))))
		return (NULL);
	while (i < words)
		if (*s != c)
		{
			j = ft_nextwordl(s, c);
			if (!(res[i] = ft_strnew(j)))
				return (ft_freeprev(&res, i));
			res[i] = ft_strncpy(res[i], s, j);
			s += j;
			i++;
		}
		else
			s++;
	return (res);
}
