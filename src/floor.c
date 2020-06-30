/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:58:01 by hdean             #+#    #+#             */
/*   Updated: 2020/06/30 17:39:42 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	void	calculations_floor(t_wolf3d *wolf, t_vec3d *floor_step,
														t_vec3d *floor, int y)
{
	t_vec3d	dir_left;
	t_vec3d	dir_right;
	double	row_dist;
	double	p;

	dir_left.x = wolf->player->view.x - wolf->cam.x;
	dir_left.y = wolf->player->view.y - wolf->cam.y;
	dir_right.x = wolf->player->view.x + wolf->cam.x;
	dir_right.y = wolf->player->view.y + wolf->cam.y;
	p = y - (WOLF_WINDOW_H >> 1);
	row_dist = (WOLF_WINDOW_H >> 1) / p;
	floor_step->x = row_dist * (dir_right.x - dir_left.x) / WOLF_WINDOW_W;
	floor_step->y = row_dist * (dir_right.y - dir_left.y) / WOLF_WINDOW_W;
	floor->x = wolf->player->pos.x + row_dist * dir_left.x;
	floor->y = wolf->player->pos.y + row_dist * dir_left.y;
}

static	int	calculation_text_floor(t_vec3d *floor, t_vec3d *floor_step)
{
	t_vec3i	t;
	t_vec3i	cell;

	cell.x = (int)floor->x;
	cell.y = (int)floor->y;
	t.x = (int)(CHUNK_SIZE * (floor->x - cell.x)) & (CHUNK_SIZE - 1);
	t.y = (int)(CHUNK_SIZE * (floor->y - cell.y)) & (CHUNK_SIZE - 1);
	floor->x += floor_step->x;
	floor->y += floor_step->y;
	return (t.x + CHUNK_SIZE * t.y);
}

static void floor_casting(t_wolf3d *wolf)
{
	t_vec3d floor_step;
	t_vec3d floor;
	t_vec3i	i;
	int		color;
	int		*tmp;

	i.y = -1;
	tmp = (int *)wolf->w_surf->pixels;
	while (++i.y < WOLF_WINDOW_H)
	{
		calculations_floor(wolf, &floor_step, &floor, i.y);
		i.x = -1;
		while (++i.x < WOLF_WINDOW_W)
		{
			i.z = calculation_text_floor(&floor, &floor_step);
			color = *((int *)wolf->textures->ceiling[0]->pixels + i.z);
			tmp[i.x + WOLF_WINDOW_W * (WOLF_WINDOW_H - i.y - 1)] = color;
			color = *((int *)wolf->textures->floor[0]->pixels + i.z);
			tmp[i.x + WOLF_WINDOW_W * i.y] = color;
		}
	}
}

void    draw_floor_ceiling(t_wolf3d *wolf)
{
	int i;
	int end_point;
	int *tmp;

	//SDL_FillRect(wolf->w_surf, NULL, 0x00000000);
	if (wolf->textures->flag == 1) 
	{
		end_point = WOLF_WINDOW_W * WOLF_WINDOW_H;
		tmp = (int *)(wolf->w_surf->pixels);
		i = 0;
		while (i < end_point / 2)
			tmp[i++] = CEILING_COLOR;
		while (i < end_point)
			tmp[i++] = FLOOR_COLOR;
	} 
	else if (wolf->textures->flag == 2)
		floor_casting(wolf);
}
