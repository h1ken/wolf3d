/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:57:51 by cstripeb          #+#    #+#             */
/*   Updated: 2020/03/11 21:46:58 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		put_pixel_to_surf(int x, int y, SDL_Surface *trgt,
								unsigned int color)
{
	uint32_t *tmp;

	if (x >= 0 && y >= 0 && x < trgt->w && y < trgt->h)
	{
		tmp = (uint32_t *)trgt->pixels;
		tmp[x + y * trgt->w] = color;
	}
}

SDL_Surface	*create_surface(int w, int h)
{
	SDL_Surface *res;

	res = SDL_CreateRGBSurface(0, w, h, 32, R_MASK, G_MASK, B_MASK, A_MASK);
	if (!res)
	{
		ft_putendl("heh");
		return (NULL);
	}
	SDL_SetSurfaceBlendMode(res, SDL_BLENDMODE_NONE);
	ft_bzero(res->pixels, res->h * res->pitch);
	return (res);
}

void	draw_wall(t_wolf3d *wolf, t_vec3i cell, double wall_dist, int side)
{
	int lineHeight = (int)(WOLF_WINDOW_H / wall_dist);
	int drawStart = (-lineHeight >> 1) + (WOLF_WINDOW_H >> 1);
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = (lineHeight >> 1) + (WOLF_WINDOW_H >> 1);
	if (drawEnd >= WOLF_WINDOW_H)
		drawEnd = WOLF_WINDOW_H - 1;
	int color = 0;
	if (wolf->map->grid[cell.y][cell.x] == 1)
		color = 0x00ff0000;
	else if (wolf->map->grid[cell.y][cell.x] == 2)
		color = 0x000000ff;
	if (side == 1)
		color = 0x00ff0000;
	else if (side == 2)
		color = 0x0000ff00;
	else if (side == 3)
		color = 0x000000ff;
	else if (side == 0)
		color = 0x00ff0000;
	int tmp;
	tmp = 0;
	while (drawStart + tmp < drawEnd)
	{
		put_pixel_to_surf(cell.z, drawStart + tmp, wolf->w_surf, color);
		tmp++;
	}
}
