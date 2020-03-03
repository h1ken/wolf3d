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

static int	check_events(t_wolf3d *wolf, t_sdl_info *i_sdl)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			return (0);
		else if (e.type == SDL_KEYDOWN)
			return (key_press_handle(e.key, wolf));
		else if (e.type == SDL_KEYUP)
			return (key_up_handle(e.key, wolf));
	}
	return (1);
}

void		loop(t_wolf3d *wolf, t_sdl_info *i_sdl)
{
	int	x;
	float	dirX, dirY;

	wolf->w_surf = SDL_GetWindowSurface(i_sdl->w);
	x = 1;
	SDL_UpdateWindowSurface(i_sdl->w);
	dirX = -1;
	dirY = 0;
	while (x)
	{
		x = check_events(wolf, i_sdl);
		SDL_UpdateWindowSurface(i_sdl->w);
	}
}
