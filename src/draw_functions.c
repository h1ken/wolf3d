#include "wolf3d.h"
#include <stdint.h>

void	put_pixel_to_surf(int x, int y, SDL_Surface *trgt, unsigned int color)
{
	uint32_t *tmp;

    if (x >= 0 && y >= 0 && x < trgt->w && y < trgt->h)
    {
        tmp = (uint32_t *)trgt->pixels;
        tmp[x + y * trgt->w] = color;
    }
}
