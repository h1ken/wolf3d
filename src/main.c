/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:39:30 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/18 18:32:38 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_wolf3d	*wolf;
	t_sdl_info	*i_sdl;

	init(&wolf, &i_sdl);
	i_sdl->w = SDL_CreateWindow("The allmighty WOLF, but..",
							SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							WOLF_WINDOW_W, WOLF_WINDOW_H,
							SDL_WINDOW_SHOWN);
	if (i_sdl->w == NULL)
	{
		ft_putendl("Hello");
		return (1);
	}
	loop(wolf, i_sdl);
	SDL_Quit();
	return (0);
}