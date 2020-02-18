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

	uint32_t *ttmp;
	wolf->w_surf = SDL_GetWindowSurface(i_sdl->w);
	ttmp = (uint32_t *)wolf->w_surf->pixels;
x = -1;
	while (++x < 20)
	{
		ttmp[10 + x * wolf->w_surf->w] = 0x00ff00ff;
		ttmp[11 + x * wolf->w_surf->w] = 0x00ff00ff;
		ttmp[12 + x * wolf->w_surf->w] = 0x00ff00ff;
		ttmp[13 + x * wolf->w_surf->w] = 0x00ffffff;
		ttmp[14 + x * wolf->w_surf->w] = 0x00ffffff;
	}
	SDL_UpdateWindowSurface(i_sdl->w);
	x = 0;
	while (!x)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				x = 1;
		}
	}
}
