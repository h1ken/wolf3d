/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:20:18 by cstripeb          #+#    #+#             */
/*   Updated: 2020/07/01 19:08:10 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		check_events(t_wolf3d *wolf)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			return (0);
		else if (e.type == SDL_KEYDOWN)
			return (key_press_handle(e.key.keysym.sym, wolf));
		else if (e.type == SDL_KEYUP)
			return (key_up_handle(e.key.keysym.sym, wolf));
	}
	return (1);
}

t_ray			get_dir_ray(t_wolf3d *wolf, double camera_x)
{
	t_ray	res;

	res.dir.x = wolf->player->view.x + wolf->cam.x * camera_x;
	res.dir.y = wolf->player->view.y + wolf->cam.y * camera_x;
	res.delta_dist.x = fabs(1 / res.dir.x);
	res.delta_dist.y = fabs(1 / res.dir.y);
	return (res);
}

static void		expand_ray(t_wolf3d *wolf, t_ray *dr, t_vec3i *cell,
							t_vec3i step)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (dr->side_dist.x < dr->side_dist.y)
		{
			dr->side_dist.x += dr->delta_dist.x;
			cell->x += step.x;
			dr->side = step.x > 0 ? 0 : 1;
		}
		else
		{
			dr->side_dist.y += dr->delta_dist.y;
			cell->y += step.y;
			dr->side = step.y > 0 ? 2 : 3;
		}
		if (wolf->map->grid[cell->y][cell->x] > 0)
			hit = 1;
	}
}

double			perform_dda(t_wolf3d *wolf, t_ray *dir_ray, t_vec3i *cell)
{
	double	wall_dist_perp;
	t_vec3i	step;

	step.x = dir_ray->dir.x < 0 ? -1 : 1;
	step.y = dir_ray->dir.y < 0 ? -1 : 1;
	dir_ray->side_dist.x = dir_ray->delta_dist.x * (dir_ray->dir.x < 0 ?
										(wolf->player->pos.x - cell->x) :
										(cell->x + 1.0 - wolf->player->pos.x));
	dir_ray->side_dist.y = dir_ray->delta_dist.y * (dir_ray->dir.y < 0 ?
										(wolf->player->pos.y - cell->y) :
										(cell->y + 1.0 - wolf->player->pos.y));
	expand_ray(wolf, dir_ray, cell, step);
	if (dir_ray->side <= 1)
		wall_dist_perp = (cell->x - wolf->player->pos.x + (1 - step.x) / 2)
							/ dir_ray->dir.x;
	else
		wall_dist_perp = (cell->y - wolf->player->pos.y + (1 - step.y) / 2)
							/ dir_ray->dir.y;
	return (wall_dist_perp);
}

void			loop(t_wolf3d *wolf, t_sdl_info *isdl)
{
	int		event;

	wolf->oldtime = SDL_GetTicks();
	wolf->time = SDL_GetTicks();
	wolf->ftime = 0;
	wolf->w_surf = SDL_GetWindowSurface(isdl->w);
	SDL_UpdateWindowSurface(isdl->w);
	event = 1;
	while (event)
	{
		wolf->time = SDL_GetTicks();
		wolf->ftime = wolf->time - wolf->oldtime;
		if (wolf->ftime >= 1000.0 / 61.0)
		{
			do_raycasting_magic(wolf);
			draw_weapon(wolf);
			SDL_UpdateWindowSurface(isdl->w);
			wolf->oldtime = wolf->time;
			event = check_events(wolf);
		}
	}
}
