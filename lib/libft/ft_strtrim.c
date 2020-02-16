/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:32:54 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/17 14:13:26 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_iswhite(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s);
	while (ft_iswhite(s[start]))
		start++;
	while (end > 0 && ft_iswhite(s[end - 1]))
		end--;
	if (!(res = ft_strnew(end > start ? end - start : 0)))
		return (NULL);
	while (start + i < end)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}
