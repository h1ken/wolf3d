/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:54:33 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/06 20:27:03 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t last_pos;
	size_t i;
	size_t count;

	if (c == 0 && !(*s))
		return ((char *)s);
	i = 0;
	count = 0;
	last_pos = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			last_pos = i;
			count++;
		}
		i++;
	}
	if (count || (c == 0 && (last_pos = i)))
		return ((char *)(s + last_pos));
	return (NULL);
}
