/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:57:51 by cstripeb          #+#    #+#             */
/*   Updated: 2020/03/14 10:13:10 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	pick_color(t_wolf3d *wolf, t_vec3i cell, int side)
{
	int color;

	if (wolf->map->grid[cell.y][cell.x] == 1)
		color = 0x007f0000;
	else if (wolf->map->grid[cell.y][cell.x] == 2)
		color = 0x0000007f;
	if (side == 0)
		color = color * 2;
	else if (side == 1)
		color = color | 0x00ff0000;
	else if (side == 2)
		color = color;
	else if (side == 3)
		color = color;
	return (color);
}

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

void		draw_wall(t_wolf3d *wolf, t_vec3i cell, double wall_dist, int side)
{
	int line_h;
	int draw_start;
	int draw_end;
	int tmp;

	line_h = (int)(WOLF_WINDOW_H / wall_dist);
	draw_start = (-line_h >> 1) + (WOLF_WINDOW_H >> 1);
	draw_end = (line_h >> 1) + (WOLF_WINDOW_H >> 1);
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WOLF_WINDOW_H)
		draw_end = WOLF_WINDOW_H - 1;
	;
	tmp = 0;
	while (draw_start + tmp < draw_end)
	{
		put_pixel_to_surf(cell.z, draw_start + tmp, wolf->w_surf,
							pick_color(wolf, cell, side));
		tmp++;
	}
}
