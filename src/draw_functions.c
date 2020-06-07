/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:57:51 by cstripeb          #+#    #+#             */
/*   Updated: 2020/03/14 14:01:00 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h> //delete

static int	pick_color(t_wolf3d *wolf, t_vec3i cell, int side)
{
	int color;

	if (wolf->map->grid[cell.y][cell.x] == 1)
		color = 0x007f0000;
	else if (wolf->map->grid[cell.y][cell.x] == 2)
		color = 0x0000007f;
	if (side == 0)
		color = 0x0023aa23;
	else if (side == 1)
		color = 0x00a2aa77;
	else if (side == 2)
		color = 0x00882288;
	else if (side == 3)
		color = 0x001277aa;
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

int      count_tex_x(t_wolf3d *wolf, double wall_dist, t_ray *ray_dir)
{
    int     side;
    double  wall_x;
    int     tex_x;

    side = ray_dir->side;
    if (side <= 1)
        wall_x = wolf->player->pos.y + wall_dist * ray_dir->dir.y;
    else
        wall_x = wolf->player->pos.x + wall_dist * ray_dir->dir.x;
    wall_x -= floor(wall_x);
    tex_x = (int)(wall_x * CHUNK_SIZE);
    if ((side <= 1 && ray_dir->dir.x > 0) || (side > 1 && ray_dir->dir.y > 0))
        tex_x = CHUNK_SIZE - tex_x - 1;

    return (tex_x);
}

//void		draw_wall(t_wolf3d *wolf, t_vec3i cell, double wall_dist, int side)
void		draw_wall(t_wolf3d *wolf, t_vec3i cell, double wall_dist, t_ray *ray_dir)

{
	int line_h;
	int draw_start;
	int draw_end;
	int tmp;
    int side = ray_dir->side; //fix later

	line_h = (int)(WOLF_WINDOW_H / wall_dist);
	draw_start = (-line_h >> 1) + (WOLF_WINDOW_H >> 1);
	draw_end = (line_h >> 1) + (WOLF_WINDOW_H >> 1);
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WOLF_WINDOW_H)
		draw_end = WOLF_WINDOW_H - 1;
////////////////////////////////////////////////////
	wolf->textures->x = count_tex_x(wolf, wall_dist, ray_dir);
	wolf->textures->step = 1.0 * CHUNK_SIZE / line_h;
	wolf->textures->pos = (draw_start - (WOLF_WINDOW_H >> 1) +
	                                    (line_h >> 1)) * wolf->textures->step;
	tmp = 0;
	int color;
	int *text = (int *)(wolf->textures->tex[side]->pixels);
	////////////////////////////////////////////////
	while (draw_start + tmp < draw_end)
	{
	    if (wolf->textures->flag == 0)
	        color = pick_color(wolf, cell, side);
	    else
        {
            wolf->textures->y = (int)(round(wolf->textures->pos)) & (CHUNK_SIZE - 1);
            wolf->textures->pos += wolf->textures->step;
            color = *(text +
                    wolf->textures->x + CHUNK_SIZE * wolf->textures->y);
	        if (side == 1 || side == 2)
	            color = (color >> 1) & 8355711;
        }
//		put_pixel_to_surf(cell.z, draw_start + tmp, wolf->w_surf,
//							pick_color(wolf, cell, side));
        put_pixel_to_surf(cell.z, draw_start + tmp, wolf->w_surf,
							color);
		tmp++;
	}
}
