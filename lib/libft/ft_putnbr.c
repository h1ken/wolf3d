/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:13:40 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/15 19:39:37 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n / -10 != 0)
			ft_putnbr(n / -10);
		ft_putchar('0' - n % 10);
	}
	else if (n / 10 == 0)
	{
		ft_putchar('0' + n);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + n % 10);
	}
}
