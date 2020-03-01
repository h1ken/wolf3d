/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:15:16 by cstripeb          #+#    #+#             */
/*   Updated: 2020/03/01 16:37:27 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	init_wolf3d(t_wolf3d **wolf)
{
	if (!(*wolf = (t_wolf3d *)ft_memalloc(sizeof(**wolf))))
		terminate("t_wolf3d malloc");
	if (!((*wolf)->map = (t_map *)ft_memalloc(sizeof(*((*wolf)->map)))))
		terminate("Malloc error for t_map");
	(*wolf)->map->w = 0;
	(*wolf)->map->h = 0;
	if (!((*wolf)->player = (t_unit *)ft_memalloc(sizeof(*((*wolf)->player)))))
		terminate("t_unit malloc (player)");
	(*wolf)->player->pos.x = -1;
	(*wolf)->player->pos.y = -1;
	return (0);
}

static int	init_sdl_info(t_sdl_info **i_sdl)
{
	if (!(*i_sdl = (t_sdl_info *)ft_memalloc(sizeof(**i_sdl))))
		terminate("i_sdl malloc");
	if (SDL_Init(SDL_INIT_EVERYTHING))
		terminate("SDL_Init error");
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
		terminate("Error in window creation");
	return (0);
}

int			create_grid(t_wolf3d *wolf)
{
	int i;

	wolf->map->grid = (uint32_t **)ft_memalloc(sizeof(*(wolf->map->grid))
												* wolf->map->h);
	if (!wolf->map->grid)
		terminate("Grid creation error, lines array");
	i = 0;
	while (i < wolf->map->h)
	{
		wolf->map->grid[i] = (uint32_t *)ft_memalloc(sizeof(**(wolf->map->grid))
														* wolf->map->w);
		if (!wolf->map->grid[i])
			terminate("Grid creation error, lines");
		i++;
	}
	return (0);
}
