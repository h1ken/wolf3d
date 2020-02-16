/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:05:21 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/30 11:58:00 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *res;

	size = size + 1 == 0 ? size : size + 1;
	if (!(res = (char *)malloc(sizeof(*res) * size)))
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
