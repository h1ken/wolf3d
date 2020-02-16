/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:49:02 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/06 21:04:41 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*where;
	unsigned char	*what;
	size_t			i;

	where = (unsigned char *)dst;
	what = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*where = what[i];
		where++;
		i++;
	}
	return (dst);
}
