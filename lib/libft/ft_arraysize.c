/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraysize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 09:38:01 by cstripeb          #+#    #+#             */
/*   Updated: 2020/01/13 15:19:29 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function returns size of a null-terminated array
*/

size_t	ft_arraysize(const void *array, const size_t elem_size)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = 0;
	flag = 1;
	while (flag)
	{
		j = 0;
		flag = 0;
		while (j < elem_size)
		{
			flag += (*((char *)array + i + j) ^ 0);
			j++;
		}
		i += elem_size;
	}
	return (i / elem_size - 1);
}
