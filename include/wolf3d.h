/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:37:11 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/28 16:36:59 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <stdint.h>
# include <errno.h>
# include <SDL.h>
# include "libft.h"
# include "wolf3d_defines.h"

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
	float			view_x;
	int			view_y;
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
	uint32_t	**grid;
	uint32_t	w;
	uint32_t	h;
	SDL_Surface	*m_surf;
}				t_map;

typedef struct	s_wolf3d
{
	t_unit		*player;
	SDL_Surface	*w_surf;
	t_map		*map;
}				t_wolf3d;

int				init(t_wolf3d **wolf, t_sdl_info **i_sdl);
void			terminate(char *msg);
void			loop(t_wolf3d *wolf, t_sdl_info *i_sdl);
void			put_pixel_to_surf(int x, int y, SDL_Surface *trgt,
									unsigned int color);
int				key_press_handle(SDL_KeyboardEvent e, t_wolf3d *wolf);
int				key_up_handle(SDL_KeyboardEvent e, t_wolf3d *wolf);
int				read_map(char *f_name, t_wolf3d *wolf);
int				create_window(t_sdl_info *i_sdl);
SDL_Surface		*create_surface(int w, int h);
#endif
