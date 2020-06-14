/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:37:17 by cstripeb          #+#    #+#             */
/*   Updated: 2020/03/14 12:57:39 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINES_H
# define WOLF3D_DEFINES_H

# define WOLF_WINDOW_NAME "The allmighty WOLF, but.."
# define WOLF_WINDOW_W 640
# define WOLF_WINDOW_H 480

# define CHUNK_SIZE 64

# define A_MASK 0xff000000
# define R_MASK 0x00ff0000
# define G_MASK 0x0000ff00
# define B_MASK 0x000000ff

# define VALID_MAP_SYMBOLS " cwadbp"

# define GO_FORWARD SDLK_w
# define GO_BACKWARD SDLK_s
# define TURN_LEFT SDLK_a
# define TURN_RIGHT SDLK_d
# define EXIT_KEY SDLK_ESCAPE
# define TURN_TEXTURES SDLK_t

# define FLOOR_COLOR 0x00505050
# define CEILING_COLOR 0x0000BFFF

#endif
