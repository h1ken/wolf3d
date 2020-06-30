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

int	main(int ac, char **av)
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
	SDL_DestroyWindow(i_sdl->w);
	Mix_Quit();
	SDL_Quit();
	return (0);
}
