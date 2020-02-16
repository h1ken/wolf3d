/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:23:31 by cstripeb          #+#    #+#             */
/*   Updated: 2019/05/11 16:15:15 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (s1 && s2)
	{
		res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (!res)
			return (NULL);
		res = ft_strcpy(res, s1);
		res = ft_strcat(res, s2);
		return (res);
	}
	return (NULL);
}
