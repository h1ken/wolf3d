/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:20:18 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/18 22:12:54 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdint.h>

void	loop(t_wolf3d *wolf, t_sdl_info *i_sdl)
{
	int			x;
	SDL_Event	e;

	wolf->w_surf = SDL_GetWindowSurface(i_sdl->w);
	x = 0;
	while (x != -1)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				x = -1;
			if (e.type == SDL_KEYDOWN)
			{
				put_pixel_to_surf(x, x, wolf->w_surf, 0x000fffff);
				x++;
				SDL_UpdateWindowSurface(i_sdl->w);
			}
		}
	}
}
