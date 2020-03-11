/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:20:18 by cstripeb          #+#    #+#             */
/*   Updated: 2020/03/11 17:59:54 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static int	check_events(t_wolf3d *wolf, t_sdl_info *i_sdl)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			return (0);
		else if (e.type == SDL_KEYDOWN)
			return (key_press_handle(e.key, wolf));
		else if (e.type == SDL_KEYUP)
			return (key_up_handle(e.key, wolf));
	}
	return (1);
}

static t_vec3d	get_dir_ray(t_wolf3d *wolf, double cameraX)
{
	t_vec3d	res;

	res.x = wolf->player->view.x + wolf->cam.x * cameraX;
	res.y = wolf->player->view.y + wolf->cam.y * cameraX;
	return (res);
}

void		test_raycast(t_wolf3d *wolf, t_sdl_info *isdl)
{
	t_vec3d dir_ray;
	t_vec3i cell;
	int event;
	int x;

	event = 1;
	while (event)
	{
		x = -1;
		SDL_FillRect(wolf->w_surf, NULL, 0x00000000);
		while (++x < WOLF_WINDOW_W)
		{
			dir_ray = get_dir_ray(wolf, 2 * x / (double)(WOLF_WINDOW_W) - 1);
			cell = get_player_pos_integer(wolf);
			double sideDistX;
			double sideDistY;
			double deltaDistX = fabs(1 / dir_ray.x);
			double deltaDistY = fabs(1 / dir_ray.y);
			double WallDistPerpen;
			int stepX;
			int stepY;
			int hit = 0;
			int side;
			if (dir_ray.x < 0)
			{
				stepX = -1;
				sideDistX = (wolf->player->pos.x - cell.x) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (cell.x + 1.0 - wolf->player->pos.x) * deltaDistX;
			}
			if (dir_ray.y < 0)
			{
				stepY = -1;
				sideDistY = (wolf->player->pos.y - cell.y) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (cell.y + 1.0 - wolf->player->pos.y) * deltaDistY;
			}
			while (hit == 0)
			{
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					cell.x += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					cell.y += stepY;
					side = 1;
				}
				if (wolf->map->grid[cell.y][cell.x] > 0)
					hit = 1;
			}
			if (side == 0)
				WallDistPerpen = (cell.x - wolf->player->pos.x + (1 - stepX) / 2) / dir_ray.x;
			else
				WallDistPerpen = (cell.y - wolf->player->pos.y + (1 - stepY) / 2) / dir_ray.y;
			int lineHeight = (int)(WOLF_WINDOW_H / WallDistPerpen);
			int drawStart = (-lineHeight >> 1) + (WOLF_WINDOW_H >> 1);
			if (drawStart < 0)
				drawStart = 0;
			int drawEnd = (lineHeight >> 1) + (WOLF_WINDOW_H >> 1);
			if (drawEnd >= WOLF_WINDOW_H)
				drawEnd = WOLF_WINDOW_H - 1;
			int color;
			if (wolf->map->grid[cell.y][cell.x] == 1)
				color = 0x00ff0000;
			else if (wolf->map->grid[cell.y][cell.x] == 2)
				color = 0x000000ff;
			else
				color = 0x00000000;
			if (side == 1)
				color >>= 1;
			int tmp;
			tmp = 0;
			while (drawStart + tmp < drawEnd)
			{
				put_pixel_to_surf(x, drawStart + tmp, wolf->w_surf, color);
				tmp++;
			}
		}
		SDL_UpdateWindowSurface(isdl->w);
		event = check_events(wolf, isdl);
	}
}


void		loop(t_wolf3d *wolf, t_sdl_info *i_sdl)
{
	int	x;

	wolf->w_surf = SDL_GetWindowSurface(i_sdl->w);
	x = 1;
	SDL_UpdateWindowSurface(i_sdl->w);
	test_raycast(wolf, i_sdl);
	//while (x)
	//{
	//	x = check_events(wolf, i_sdl);
	//	SDL_UpdateWindowSurface(i_sdl->w);
	//}
}
