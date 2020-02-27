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

void	loop(t_wolf3d *wolf, t_sdl_info *i_sdl)
{
	int			x;
	SDL_Event	e;

	wolf->w_surf = SDL_GetWindowSurface(i_sdl->w);
	x = 0;
	SDL_UpdateWindowSurface(i_sdl->w);
	while (x != -1)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				x = -1;
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
					x = -1;
			}
			SDL_UpdateWindowSurface(i_sdl->w);
		}
	}
}
