/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:05:04 by h1ken             #+#    #+#             */
/*   Updated: 2020/06/30 17:00:09 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	check_player_pos(t_wolf3d *wolf)
{
	int x;
	int y;

	y = (int)(wolf->player->pos.y);
	x = (int)(wolf->player->pos.x);
	if (wolf->map->grid[y - 1][x - 1] != 0)
		terminate("Map error: Player's starting position is in wall.");
	wolf->player->pos.x -= 0.5;
	wolf->player->pos.y -= 0.5;
}

void		ft_validator(t_wolf3d *wolf)
{
	int i;

	i = 0;
	while (i < wolf->map->h)
	{
		if (wolf->map->grid[i][0] != 1 ||
			wolf->map->grid[i][wolf->map->w - 1] != 1)
			terminate("Map error: Missing outer wall");
		i++;
	}
	i = 0;
	while (i < wolf->map->w)
	{
		if (wolf->map->grid[0][i] != 1 ||
			wolf->map->grid[wolf->map->h - 1][i] != 1)
			terminate("Map error: Missing outer wall");
		i++;
	}
	check_player_pos(wolf);
}
