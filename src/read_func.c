/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:02:33 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/29 18:36:44 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>

static void	get_map_w_h(t_wolf3d *wolf, char *s)
{
	wolf->map->w = ft_atoi(s);
	wolf->map->h = ft_atoi(ft_strchr(s, ' '));
	if (wolf->map->w == 0 || wolf->map->h  == 0)
		terminate("Check your map (map dimensions)");
}

static void	get_player_pos(t_wolf3d *wolf, char *s)
{
	if ((wolf->player->pos.x = ft_atoi(s)) == 0 ||
			(wolf->player->pos.y = ft_atoi(ft_strchr(s, ' ') + 1)) == 0)
		terminate("Check your map (player pos)");
}

int			read_map(char *f_name, t_wolf3d *wolf)
{
	t_list	*lst;
	char	*s;
	int		got;
	int		fd;

	errno = 0;
	if ((fd = open(f_name, O_RDONLY)) == -1)
		terminate("An error occured while reading");
	while ((got = get_next_line(fd, &s)) == 1)
	{
		if (wolf->map->h == 0)
			get_map_w_h(wolf, s);
		else if (wolf->player->pos.x == -1)
			get_player_pos(wolf, s);
		else
		{
			if (ft_strlen(s) != wolf->map->w)
				terminate("Check your map (different length string)");
		}
		free(s);
	}
	if (got == -1)
		terminate("Read error");
	return (0);
}
