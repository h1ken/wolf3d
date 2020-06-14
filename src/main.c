/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:39:30 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/29 17:20:18 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


void print_sprites(t_sprite *s)
{
	printf("Num of sprites: %d\n", s->amount);
	for (int i = 0; i < s->amount; i++)
	{
		printf("%d. (%.2f, %.2f) obj: %d\n", i, s->obj[i].x, s->obj[i].y, s->obj[i].object);
	}
}

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
	read_sprites(wolf);
//	print_sprites(wolf->sprite);
	loop(wolf, i_sdl); ////////////////////////////////////////////////////////
	SDL_DestroyWindow(i_sdl->w);
	SDL_Quit();
	return (0);
}
