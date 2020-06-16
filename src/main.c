/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h1ken <h1ken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:39:30 by cstripeb          #+#    #+#             */
/*   Updated: 2020/06/16 15:38:50 by h1ken            ###   ########.fr       */
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
	loop(wolf, i_sdl); ////////////////////////////////////////////////////////
	SDL_DestroyWindow(i_sdl->w);
	Mix_Quit();
	SDL_Quit();
	return (0);
}
