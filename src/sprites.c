#include "wolf3d.h"
#include <math.h>

void	read_sprites(t_wolf3d *wolf)
{
	int i;
	int j;

	if (!(wolf->sprite = (t_sprite *)ft_memalloc(sizeof(t_sprite))))
		terminate("Malloc doesn't work in sprites");
	wolf->sprite->amount = 0;
	j = 0;
	while (++j < wolf->map->h - 1)
	{
		i = 0;
		while (++i < wolf->map->w - 1)
		{
			if (wolf->map->grid[j][i] == 5 || wolf->map->grid[j][i] == 6)
			{
				printf("%d, %d\n", j, i);
				if (wolf->sprite->amount <= 5)
				{
					wolf->sprite->obj[wolf->sprite->amount].x = i;
					wolf->sprite->obj[wolf->sprite->amount].y = j;
					wolf->sprite->obj[wolf->sprite->amount].object =
							(wolf->map->grid[j][i] == 5) ? 0 : 1;
					(wolf->sprite->amount)++;
				}
				wolf->map->grid[j][i] = 0;
			}
		}
	}
}

void sort_sprites(int *order, double *dist, int num)
{
	int i;
	int j;
	int order_old;
	double dist_old;

	i = 0;
	while (i < num - 1)
	{
		j = 0;
		while (j < num - 1)
		{
			if (dist[j] < dist[j + 1])
			{
				order_old = order[j];
				dist_old = dist[j];
				order[j] = order[j + 1];
				order[j + 1] = order_old;
				dist[j] = dist[j + 1];
				dist[j + 1] = dist_old;
			}
			j++;
		}
		i++;
	}
}


void	draw_sprites(t_wolf3d *wolf, t_ray *dir)
{
	int sprite_order[5];
	double sprite_dist[5];
	int i;
	t_vec3d sprite;
	double inv_det;
	t_vec3d transf;
	int screen;
	int h;
	int w;
	int draw_start_x;
	int draw_end_x;
	int draw_start_y;
	int draw_end_y;

	i = 0;
	printf("pos (%.2f, %.2f)\n", wolf->player->pos.x, wolf->player->pos.y);
	while (i < wolf->sprite->amount)
	{
		sprite_order[i] = i;
		sprite_dist[i] = (wolf->cam.x - wolf->sprite->obj[i].x) *
				(wolf->cam.x - wolf->sprite->obj[i].x) +
				(wolf->cam.y - wolf->sprite->obj[i].y) *
				(wolf->cam.y - wolf->sprite->obj[i].y);
		i++;
	}
	sort_sprites(sprite_order, sprite_dist, wolf->sprite->amount);
	i = 0;
	while (i < wolf->sprite->amount)
	{
		printf("Object %d\n", sprite_order[i]);
		sprite.x = wolf->sprite->obj[sprite_order[i]].x - wolf->cam.x;
		sprite.y = wolf->sprite->obj[sprite_order[i]].y - wolf->cam.y;

//		sprite.x = wolf->sprite->obj[sprite_order[i]].x;
//		sprite.y = wolf->sprite->obj[sprite_order[i]].y;

		printf("sprite position: (%.2f, %.2f)\n", sprite.x, sprite.y);

		inv_det = 1.0 / (wolf->cam.x * dir->dir.y - dir->dir.x * wolf->cam.y);

		transf.x = inv_det * (dir->dir.y * sprite.x - dir->dir.x * sprite.y);
		transf.y = inv_det * (-wolf->cam.y * sprite.x + wolf->cam.x * sprite.y);

		printf("trans: (%.2f, %.2f)\n", transf.x, transf.y);


		screen = (int)((WOLF_WINDOW_W >> 1) * (1 + transf.x / transf.y));
		printf("screen %d\n", screen);

		h = abs((int)(WOLF_WINDOW_H / transf.y));
		printf("Height: %d ", h);

		draw_start_y = -(h >> 1) + (WOLF_WINDOW_H >> 1);
		if (draw_start_y < 0)
			draw_start_y = 0;

		draw_end_y = (h >> 1) + (WOLF_WINDOW_H >> 1);
		if (draw_end_y >= WOLF_WINDOW_H)
			draw_end_y = WOLF_WINDOW_H - 1;

		w = abs((int)(WOLF_WINDOW_H/transf.y));
		printf("Width: %d\n", w);

		draw_start_x = -(w >> 1) + screen; //something here
		if (draw_start_x < 0)
			draw_start_x = 0;

		draw_end_x = (w >> 1) + screen;
		if (draw_end_x >= WOLF_WINDOW_W)
			draw_end_x = WOLF_WINDOW_W - 1;

		printf("draw_start_x %d, draw_end_x %d\n", draw_start_x, draw_end_x);
		printf("draw_start_y %d, draw_end_y %d\n\n", draw_start_y, draw_end_y);
//		for (int k = 0; k < WOLF_WINDOW_W;k++)
//			printf("%.2f ", wolf->sprite->zbuffer[k]);
		printf("\n");

		while (draw_start_x < draw_end_x)
		{
			int tex_x = (int)(256 * (draw_start_x - (-w / 2 + screen)) * CHUNK_SIZE / w) / 256;
//			int tex_x = (int)((draw_start_x - (-(w >> 1) + screen)) * CHUNK_SIZE / w);
//			printf("dir %.2f\n", wolf->sprite->zbuffer[draw_start_x]);
			if (transf.y > 0 && draw_start_x > 0 && draw_start_x < WOLF_WINDOW_W &&
					transf.y < wolf->sprite->zbuffer[draw_start_x])
			{
				while (draw_start_y < draw_end_y)
				{
					int d = (draw_start_y) * 256 - WOLF_WINDOW_H * 128 + h * 128;
					int tex_y = ((d * CHUNK_SIZE) / h) / 256;
					printf("tex (%d, %d) ", tex_x, tex_y);
					int *t = (int *)wolf->textures->objects[0]->pixels;
					int color = *(t + CHUNK_SIZE * tex_y + tex_x);
					t = (int *)wolf->w_surf->pixels;
//					if (color & 0xFFFFFF)
//					{
						write(1, "1", 1);
						t[WOLF_WINDOW_W * draw_start_y + draw_start_x] = color;
//					}
					draw_start_y++;
				}
			}
			draw_start_x++;
		}


		i++;
	}
//	terminate("stupid");
}

