#include "wolf3d.h"

static SDL_Surface		*load_texture(char *path)
{
    SDL_Surface		*load_image;
    SDL_Surface		*texture;

    if (!(load_image = SDL_LoadBMP(path)))
        terminate("Can't load texture");
    texture = SDL_ConvertSurfaceFormat(load_image, SDL_PIXELFORMAT_BGRA32, 0);
    if (!texture)
        terminate("Can't modify texture");
    SDL_FreeSurface(load_image);
    return (texture);
}

int                     read_textures(t_wolf3d *wolf)
{
    if (!(wolf->textures = (t_textures *)ft_memalloc(sizeof(t_textures))))
        terminate("Malloc error for t_textures");
    wolf->textures->flag = 1;
    wolf->textures->tex[0] = load_texture("src/textures/wall0.bmp");
    wolf->textures->tex[1] = load_texture("src/textures/wall1.bmp");
    wolf->textures->tex[2]= load_texture("src/textures/wall2.bmp");
    wolf->textures->tex[3] = load_texture("src/textures/wall3.bmp");
    return (0);
}

int                     pick_texture_color()
{

}

