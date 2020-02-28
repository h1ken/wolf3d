/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:59:39 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/28 19:34:09 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	key_press_handle(SDL_KeyboardEvent e, t_wolf3d *wolf)
{
	static int i = 0;
	if (e.keysym.sym == SDLK_ESCAPE)
		return (0);
	if (e.keysym.sym == SDLK_1)
	{
			put_pixel_to_surf(10, 10 + i++, wolf->w_surf, 0x00ff0000);
	}
	return (1);
}

int	key_up_handle(SDL_KeyboardEvent e, t_wolf3d *wolf)
{
	return (1);
}
