/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:20:18 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/28 13:44:54 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	loop(t_wolf3d *wolf, t_sdl_info *i_sdl)
{
	int			x;
	SDL_Event	e;

	wolf->w_surf = SDL_GetWindowSurface(i_sdl->w);
	x = 1;
	SDL_UpdateWindowSurface(i_sdl->w);
	while (x)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				x = 0;
			else if (e.type == SDL_KEYDOWN)
				x = key_press_handle(e.key, wolf);
			else if (e.type == SDL_KEYUP)
				x = key_up_handle(e.key, wolf);
			SDL_UpdateWindowSurface(i_sdl->w);
		}
	}
}
