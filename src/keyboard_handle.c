/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h1ken <h1ken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:59:39 by cstripeb          #+#    #+#             */
/*   Updated: 2020/06/16 15:43:33 by h1ken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		rotate_kb(t_wolf3d *wolf, SDL_Keycode key)
{
	double	sin_a;
	double	old_x;

	sin_a = key == TURN_RIGHT ? wolf->rot.z : wolf->rot.y;
	old_x = wolf->player->view.x;
	wolf->player->view.x = old_x * wolf->rot.x + wolf->player->view.y * sin_a;
	wolf->player->view.y = wolf->player->view.y * wolf->rot.x - old_x * sin_a;
	old_x = wolf->cam.x;
	wolf->cam.x = old_x * wolf->rot.x + wolf->cam.y * sin_a;
	wolf->cam.y = wolf->cam.y * wolf->rot.x - old_x * sin_a;
}

static void	music_manip(SDL_Keycode key, t_wolf3d *wolf)
{
	if (key == SDLK_9 && Mix_PlayingMusic() == 0)
		Mix_PlayMusic(wolf->music, -1);
	if (key == SDLK_8)
		Mix_HaltMusic();
}

int			key_press_handle(SDL_Keycode key, t_wolf3d *wolf)
{
	if (key == EXIT_KEY)
		return (0);
	if  (key == SDLK_9 || key == SDLK_8)
		music_manip(key, wolf);
	if (key == SDLK_LSHIFT)
		wolf->player->speed = 0.5;
	if (key == GO_FORWARD)
		wolf->player->flags |= 1;
	if (key == GO_BACKWARD)
		wolf->player->flags |= (1 << 1);
	if (key == TURN_LEFT || key == TURN_RIGHT)
		rotate_kb(wolf, key);
	if (key == TURN_TEXTURES)
		wolf->textures->flag = ++(wolf->textures->flag) % 3;
	unit_move(wolf, wolf->player);
	return (1);
}

int			key_up_handle(SDL_Keycode key, t_wolf3d *wolf)
{
	if (key == SDLK_w)
		wolf->player->flags ^= 1;
	if (key == SDLK_LSHIFT)
		wolf->player->speed = 0.25;
	if (key == SDLK_s)
		wolf->player->flags ^= (1 << 1);
	if (key == SDLK_a)
		wolf->player->flags ^= (1 << 2);
	if (key == SDLK_d)
		wolf->player->flags ^= (1 << 3);
	unit_move(wolf, wolf->player);
	return (1);
}
