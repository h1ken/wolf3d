/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:39:30 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/16 20:16:06 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char **av)
{
	SDL_Window *wnd = NULL;
	SDL_Surface *srf = NULL;
	int x;
	SDL_Event e;
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		ft_putendl("Hello");
		return (1);
	}
	wnd = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_ALLOW_HIGHDPI);
	if (wnd == NULL)
	{
		ft_putendl("Hello");
		return (1);
	}
	x = 0;
	while (!x)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				x = 1;
		}
	}
	srf = SDL_GetWindowSurface(wnd);
	SDL_Quit();
	return (0);
}
