/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_rock_shooter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h1ken <h1ken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:31:02 by cstripeb          #+#    #+#             */
/*   Updated: 2020/06/10 17:14:46 by h1ken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    draw_weapon(t_sdl_info *isdl, t_wolf3d *wolf)
{
	static int	x = 0;
	int			i;
	int			j;
	int			*texture;
	int color;

	i = 0;
	texture = (int *)wolf->textures->objects[5]->pixels;
	while (i < 34)
	{
		j = 0;
		while (j < 80)
		{
			color = *(texture + i + 34 * x + j * 307);
			if ((color & 0x00FFFFFF) != 0)
				put_pixel_to_surf(370 + i, 370 + j,
									wolf->w_surf, color);
			j++;
		}
		i++;
	}
	j = SDL_GetTicks();
	x = j / 150 % 9;
}

void	get_sound(t_wolf3d *wolf)
{
	if (!(wolf->music = Mix_LoadMUS("src/music/beat.wav")))
		terminate("Error in loading music");
	Mix_PlayMusic(wolf->music, -1);
}