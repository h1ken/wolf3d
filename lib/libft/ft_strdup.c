/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:37:59 by cstripeb          #+#    #+#             */
/*   Updated: 2019/05/06 19:13:26 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*res;

	i = ft_strlen(s1);
	if (!(res = ft_strnew(i)))
		return (NULL);
	res = ft_memcpy(res, s1, i);
	return (res);
}
