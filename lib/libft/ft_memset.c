/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:31:28 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/06 20:39:54 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*where;
	unsigned char	what;

	what = (unsigned char)c;
	where = (unsigned char *)b;
	while (len > 0)
	{
		*where = what;
		where++;
		len--;
	}
	return (b);
}
