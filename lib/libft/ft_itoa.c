/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:21:44 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/30 10:46:32 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_numlen(unsigned int x)
{
	int res;

	res = x == 0 ? 1 : 0;
	while (x > 0)
	{
		res++;
		x /= 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	unsigned int	b;
	int				len;
	char			*res;
	int				flag;

	flag = n < 0 ? 1 : 0;
	b = n < 0 ? (unsigned int)-n : (unsigned int)n;
	len = flag + ft_numlen(b);
	if (!(res = (char *)malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (flag)
		res[0] = '-';
	while (len >= flag)
	{
		res[len] = '0' + b % 10;
		b /= 10;
		len--;
	}
	return (res);
}
