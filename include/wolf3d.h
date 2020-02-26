/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:37:11 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/18 19:24:23 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <SDL.h>
# include "libft.h"

# define WOLF_WINDOW_W 640
# define WOLF_WINDOW_H 480

# define CHUNK_SIZE 64

typedef unsigned int t_uint;

typedef struct	s_vec3i
{
	int			x;
	int			y;
	int			z;
}				t_vec3i;

typedef struct	s_vec3f
{
	float		x;
	float		y;
	float		z;
}				t_vec3f;

typedef struct	s_vec4f
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec4f;

typedef struct	s_unit
{
	t_vec3i		pos;
	t_vec3f		view;
	t_vec3f		move;
	char		flags;
}				t_unit;

typedef struct	s_sdl_info
{
	SDL_Window	*w;
	SDL_Surface	*s;

}				t_sdl_info;

typedef struct	s_map
{
	char		**grid;
}				t_map;

typedef struct	s_wolf3d
{
	t_unit		*player;
	SDL_Surface	*w_surf;
	t_uint		*tmp;
	t_map		*map;
}				t_wolf3d;

int				init(t_wolf3d **wolf, t_sdl_info **i_sdl);
void			loop(t_wolf3d *wolf, t_sdl_info *i_sdl);
void			put_pixel_to_surf(int x, int y, SDL_Surface *trgt,
								  unsigned int color);
#endif
