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
    wolf->textures->wall[0] = load_texture("src/textures/wall0.bmp");
    wolf->textures->wall[1] = load_texture("src/textures/wall1.bmp");
    wolf->textures->wall[2] = load_texture("src/textures/wall2.bmp");
    wolf->textures->wall[3] = load_texture("src/textures/wall3.bmp");
    wolf->textures->wall[4] = load_texture("src/textures/wall4.bmp");
    wolf->textures->wall[5] = load_texture("src/textures/wall5.bmp");
    wolf->textures->wall[6] = load_texture("src/textures/wall6.bmp");
    wolf->textures->wall[7] = load_texture("src/textures/wall7.bmp");
    wolf->textures->door[0] = load_texture("src/textures/door0.bmp");
    wolf->textures->floor[0] = load_texture("src/textures/floor0.bmp");
    wolf->textures->ceiling[0] = load_texture("src/textures/wall1.bmp");
    wolf->textures->objects[0] = load_texture("src/textures/barrel.bmp");
    wolf->textures->objects[1] = load_texture("src/textures/pillar.bmp");
    return (0);
}
