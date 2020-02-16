/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:28:04 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/15 14:40:56 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*where;
	const unsigned char	*what;

	if (dst - src > 0)
	{
		where = (unsigned char *)dst;
		what = (const unsigned char *)src;
		where += len - 1;
		what += len - 1;
		while (len > 0)
		{
			*where = *what;
			what--;
			where--;
			len--;
		}
	}
	else if (dst - src == 0)
		return (dst);
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
