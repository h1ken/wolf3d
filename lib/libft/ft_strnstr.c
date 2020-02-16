/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:16 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/06 19:47:21 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (*haystack && needle[i] && j < len)
	{
		i = 0;
		while (*(haystack + i) && needle[i] == *(haystack + i) && i + j < len)
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
		j++;
	}
	return (NULL);
}
