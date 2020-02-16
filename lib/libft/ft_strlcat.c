/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:56:30 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/11 14:17:42 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	size_t	l_dst;
	size_t	l_src;
	size_t	i;

	d = dst;
	l_src = ft_strlen(src);
	i = 0;
	while (i++ < size && *d)
		d++;
	l_dst = d - dst;
	if (l_dst >= size)
		return (size + l_src);
	i = size - l_dst;
	while (*src && i > 1)
	{
		*d++ = *src++;
		i--;
	}
	*d = '\0';
	return (l_dst + l_src);
}
