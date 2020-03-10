/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:20:18 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/28 13:44:54 by cstripeb         ###   ########.fr       */
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


void		test_raycast(t_wolf3d *wolf, t_sdl_info *isdl)
{
	int event;
	double dirX = -1;
	double dirY = 0;
	double planeX = 0;
	double planeY = 0.66;
	double time = 0;
	double oldTime = 0;
	int x;


	double distancetoplayer = (double)240 / tan(30 * M_PI / (double)180);
	event = 1;
	while (event)
	{
		x = -1;
		SDL_FillRect(wolf->w_surf, NULL, 0x00000000);
		while (++x < WOLF_WINDOW_W)
		{
			double cameraX = 2 * x / (double)(WOLF_WINDOW_W) - 1;
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;
			int mapX = (int)(wolf->player->pos.x);
			int mapY = (int)(wolf->player->pos.y);
			double sideDistX;
			double sideDistY;
			double deltaDistX = abs(1 / rayDirX);
			double deltaDistY = abs(1 / rayDirY);
			double WallDistPerpen;
			int stepX;
			int stepY;
			int hit = 0;
			int side;
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (wolf->player->pos.x - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - wolf->player->pos.x) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (wolf->player->pos.y - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - wolf->player->pos.y) * deltaDistY;
			}
			while (hit == 0)
			{
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				if (wolf->map->grid[mapY][mapX] > 0)
					hit = 1;
			}
			if (side == 0)
				WallDistPerpen = (mapX - wolf->player->pos.x + (1 - stepX) / 2) / rayDirX;
			else
				WallDistPerpen = (mapY - wolf->player->pos.y + (1 - stepY) / 2) / rayDirY;
			int lineHeight = (int)(WOLF_WINDOW_H / WallDistPerpen);
			int drawStart = -lineHeight / 2 + WOLF_WINDOW_H / 2;
			if (drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + WOLF_WINDOW_H / 2;
			if (drawEnd >= WOLF_WINDOW_H)
				drawEnd = WOLF_WINDOW_H - 1;
			int color;
			if (wolf->map->grid[mapY][mapX] == 1)
				color = 0x00ff0000;
			else if (wolf->map->grid[mapY][mapX] == 2)
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
