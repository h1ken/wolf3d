/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:12:37 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/09 17:59:08 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*what;
	unsigned char	*where;
	size_t			i;
	int				flag;

	i = 0;
	flag = 0;
	what = (unsigned char *)src;
	where = (unsigned char *)dst;
	while (i < n && !flag)
	{
		*where = what[i];
		if (what[i] == (unsigned char)c)
			flag = 1;
		where++;
		i++;
	}
	if (flag)
		return ((void *)where);
	return (NULL);
}
