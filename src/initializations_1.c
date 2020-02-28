/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:15:16 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/28 16:17:37 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	init_wolf3d(t_wolf3d **wolf)
{
	if (!(*wolf = (t_wolf3d *)ft_memalloc(sizeof(**wolf))))
	{
		ft_putendl("ALLOC");
		return (1);
	}
	return (0);
}

static int	init_sdl_info(t_sdl_info **i_sdl)
{
	if (!(*i_sdl = (t_sdl_info *)ft_memalloc(sizeof(**i_sdl))))
	{
		ft_putendl("ALLOC sdl");
		return (1);
	}
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		ft_putendl("Hello");
		return (1);
	}
	return (0);
}

int			init(t_wolf3d **wolf, t_sdl_info **i_sdl)
{
	init_wolf3d(wolf);
	init_sdl_info(i_sdl);
	return (0);
}

int			create_window(t_sdl_info *i_sdl)
{
	i_sdl->w = SDL_CreateWindow(WOLF_WINDOW_NAME,
							SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							WOLF_WINDOW_W, WOLF_WINDOW_H,
							SDL_WINDOW_SHOWN);
	if (i_sdl->w == NULL)
	{
		ft_putendl("Hello");
		return (1);
	}
	return (0);
}
