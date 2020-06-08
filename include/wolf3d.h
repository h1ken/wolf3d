/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h1ken <h1ken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:37:11 by cstripeb          #+#    #+#             */
/*   Updated: 2020/06/08 19:53:42 by h1ken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <stdint.h>
# include <errno.h>
# include "SDL/SDL.h"
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

typedef struct	s_vec3d
{
	double		x;
	double		y;
	double		z;
}				t_vec3d;

typedef struct	s_vec4f
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec4f;

typedef struct	s_vec4d
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4d;

typedef struct	s_unit
{
	t_vec3d		pos;
	t_vec3d		view;
	t_vec3d		move;
	double		speed;
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

typedef struct	s_ray
{
	t_vec3d		dir;
	t_vec3d		delta_dist;
	t_vec3d		side_dist;
	t_vec3i		step;
	int			side;
}				t_ray;

typedef struct  s_textures //mine
{
    int         flag;
    SDL_Surface *wall[15]; //check for actual quantity
    SDL_Surface *door[3];
    SDL_Surface *objects[5];
    SDL_Surface *floor[2];
    SDL_Surface *ceiling[2];
    int         x;
    int         y;
    double      step;
    double      pos;
}               t_textures;

typedef struct	s_wolf3d
{
	t_unit		*player;
	t_vec3d		rot;
	t_vec3d		cam;
	SDL_Surface	*w_surf;
	t_map		*map;
	t_textures  *textures; //mine
}				t_wolf3d;

int				init(t_wolf3d **wolf, t_sdl_info **i_sdl);
//void			draw_wall(t_wolf3d *wolf, t_vec3i cell, double wall_dist,
//							int side);
void			draw_wall(t_wolf3d *wolf, t_vec3i cell, double wall_dist, t_ray *ray_dir);
t_vec3i			get_player_pos_integer(t_wolf3d *wolf);
void			terminate(char *msg);
void			unit_move(t_wolf3d *wolf, t_unit *unit);
void			loop(t_wolf3d *wolf, t_sdl_info *i_sdl);
void			put_pixel_to_surf(int x, int y, SDL_Surface *trgt,
									unsigned int color);
int				key_press_handle(SDL_Keycode e, t_wolf3d *wolf);
int				key_up_handle(SDL_Keycode e, t_wolf3d *wolf);
void			read_map(char *f_name, t_wolf3d *wolf);
int				create_window(t_sdl_info *i_sdl);
int				create_grid(t_wolf3d *wolf);
void			print_map(t_wolf3d *wolf);
SDL_Surface		*create_surface(int w, int h);
void			ft_validator(t_wolf3d *wolf);
void			draw_weapon(t_sdl_info *isdl, t_wolf3d *wolf);

/////////////////////////
int             read_textures(t_wolf3d *wolf);
void            draw_floor_ceiling(t_wolf3d *wolf);
#endif
