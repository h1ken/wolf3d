/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 19:34:21 by hdean             #+#    #+#             */
/*   Updated: 2020/03/16 23:30:29 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Surface *load_texture(char *path, t_wolf3d *wolf)
{
    SDL_Surface     *surface;

    if (!(surface = IMG_image(path)))
        terminate("Texture reading failed");
    if (!(surface = SDL_ConvertSurfaceFormat(surface, wolf->w_surf->format, 0)))
        terminate("Texture converting failed");    
    return (surface);
}

