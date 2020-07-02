/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:39:30 by cstripeb          #+#    #+#             */
/*   Updated: 2020/06/30 17:05:14 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	free_map(t_map *map)
{
	uint32_t i;

	i = 0;
	while (i < map->h)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

static void	free_textures(t_textures *textures)
{
	SDL_FreeSurface(textures->wall[0]);
	SDL_FreeSurface(textures->wall[1]);
	SDL_FreeSurface(textures->wall[2]);
	SDL_FreeSurface(textures->wall[3]);
	SDL_FreeSurface(textures->wall[4]);
	SDL_FreeSurface(textures->wall[5]);
	SDL_FreeSurface(textures->wall[6]);
	SDL_FreeSurface(textures->wall[7]);
	SDL_FreeSurface(textures->door[0]);
	SDL_FreeSurface(textures->floor[0]);
	SDL_FreeSurface(textures->ceiling[0]);
	SDL_FreeSurface(textures->objects[5]);
}

static void	clean_all_sheeps(t_wolf3d *wolf, t_sdl_info *i_sdl)
{
	free(wolf->player);
	free_map(wolf->map);
	free(wolf->map);
	free_textures(wolf->textures);
	free(wolf->textures);
	free(wolf);
	free(i_sdl);
}

int			main(int ac, char **av)
{
	t_wolf3d	*wolf;
	t_sdl_info	*i_sdl;

	if (ac != 2)
		terminate("Usage error");
	init(&wolf, &i_sdl);
	create_window(i_sdl);
	read_map(av[1], wolf);
	read_textures(wolf);
	get_sound(wolf);
	loop(wolf, i_sdl);
	clean_all_sheeps(wolf, i_sdl);
	SDL_DestroyWindow(i_sdl->w);
	Mix_Quit();
	SDL_Quit();
	return (0);
}
