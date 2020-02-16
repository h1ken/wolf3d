/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:03:35 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/17 15:24:03 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			flag;
	long int	res;
	long int	tmp;

	while (ft_isspace(*str))
		str++;
	flag = 1;
	if (*str == '-' || *str == '+')
	{
		flag = *str == '-' ? -1 : 1;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
	{
		tmp = res;
		res = res * 10 + *str - '0';
		if (res / 10 != tmp)
			return (flag == 1 ? -1 : 0);
		str++;
	}
	return ((int)(res * flag));
}
