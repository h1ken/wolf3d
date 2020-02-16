/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:22:05 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/06 20:13:00 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	if (len == 0)
		return (dst);
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	if (i == len)
		return (dst);
	dst[i] = '\0';
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
