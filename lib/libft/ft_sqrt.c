/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:24:52 by cstripeb          #+#    #+#             */
/*   Updated: 2019/05/24 19:47:48 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_sqrt(unsigned int num)
{
	unsigned int i;

	if (num < 2)
		return (num);
	i = 2;
	while (i * i <= num)
	{
		i++;
	}
	return (--i);
}
