/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:57:51 by cstripeb          #+#    #+#             */
/*   Updated: 2020/06/30 16:53:52 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		pick_color(t_wolf3d *wolf, t_vec3i cell, int side)
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

void			put_pixel_to_surf(int x, int y, SDL_Surface *trgt,
								unsigned int color)
{
	uint32_t *tmp;

	if (x >= 0 && y >= 0 && x < trgt->w && y < trgt->h)
	{
		tmp = (uint32_t *)trgt->pixels;
		tmp[x + y * trgt->w] = color;
	}
}

static int		pick_textures(t_wolf3d *wolf, t_vec3i cell, int side)
{
	int color;
	int *texture;

	wolf->textures->y = (int)(round(wolf->textures->pos)) & (CHUNK_SIZE - 1);
	wolf->textures->pos += wolf->textures->step;
	texture = (int *)(wolf->textures->wall[side]->pixels);
	if (wolf->textures->flag == 2)
	{
		if (wolf->map->grid[cell.y][cell.x] == 2)
			texture = (int *)wolf->textures->wall[4]->pixels;
		else if (wolf->map->grid[cell.y][cell.x] == 3)
			texture = (int *)wolf->textures->wall[5]->pixels;
		else if (wolf->map->grid[cell.y][cell.x] == 4)
			texture = (int *)wolf->textures->door[0]->pixels;
	}
	color = *(texture + wolf->textures->x + CHUNK_SIZE * wolf->textures->y);
	if (side == 1 || side == 2)
		color = (color >> 1) & 8355711;
	return (color);
}

static int		count_tex_x(t_wolf3d *wolf, double wall_dist, t_ray *ray_dir)
{
	int		side;
	double	wall_x;
	int		tex_x;

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

void			draw_wall(t_wolf3d *wolf, t_vec3i cell, double wall_dist,
																t_ray *ray_dir)
{
	int line_h;
	int draw_start;
	int draw_end;
	int tmp;
	int color;

	line_h = (int)(WOLF_WINDOW_H / wall_dist);
	draw_start = (-line_h >> 1) + (WOLF_WINDOW_H >> 1) + wolf->player->pitch;
	draw_end = (line_h >> 1) + (WOLF_WINDOW_H >> 1) + wolf->player->pitch;
	draw_start = draw_start < 0 ? 0 : draw_start;
	if (draw_end >= WOLF_WINDOW_H)
		draw_end = WOLF_WINDOW_H - 1;
	wolf->textures->x = count_tex_x(wolf, wall_dist, ray_dir);
	wolf->textures->step = 1.0 * CHUNK_SIZE / line_h;
	wolf->textures->pos = (draw_start - (WOLF_WINDOW_H >> 1) +
										(line_h >> 1)) * wolf->textures->step;
	tmp = 0;
	while (draw_start + tmp < draw_end)
	{
		color = (wolf->textures->flag == 0) ?
				pick_color(wolf, cell, ray_dir->side) :
				pick_textures(wolf, cell, ray_dir->side);
		put_pixel_to_surf(cell.z, draw_start + tmp, wolf->w_surf, color);
		tmp++;
	}
}
