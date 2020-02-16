/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:58:27 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/17 16:43:40 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *new_mem;

	if (size == 0 || !(new_mem = malloc(size)))
		return (NULL);
	ft_bzero(new_mem, size);
	return (new_mem);
}
