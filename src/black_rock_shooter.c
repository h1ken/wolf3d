/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_rock_shooter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h1ken <h1ken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:31:02 by cstripeb          #+#    #+#             */
/*   Updated: 2020/06/08 22:55:51 by h1ken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    draw_weapon(t_sdl_info *isdl, t_wolf3d *wolf)
{
	static int	x = 0;
	int			i;
	int			j;

	i = 0;
	while (i < 20)
	{
		j = 1;
		while (j <= 40)
		{
			put_pixel_to_surf(320 + i + 20 * x, 479 - j,
				wolf->w_surf, 0x00000000);
			j++;
		}
		i++;
		
	}
	j = SDL_GetTicks();
	x = j / 250 % 4;
}