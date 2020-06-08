/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h1ken <h1ken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:02:33 by cstripeb          #+#    #+#             */
/*   Updated: 2020/06/08 18:45:40 by h1ken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>

static void		get_map_w_h(t_wolf3d *wolf, char *s)
{
	wolf->map->w = ft_atoi(s);
	wolf->map->h = ft_atoi(ft_strchr(s, ' '));
	if (wolf->map->w == 0 || wolf->map->h == 0)
		terminate("Check your map (map dimensions)");
	create_grid(wolf);
}

static void		get_player_pos(t_wolf3d *wolf, char *s)
{
	wolf->player->pos.x = ft_atoi(s);
	if (wolf->player->pos.x == 0 ||
			(wolf->player->pos.y = ft_atoi(ft_strchr(s, ' ') + 1)) == 0)
		terminate("Check your map (player pos)");
}

static uint32_t	parse_char(char c)
{
	if (!ft_strchr(VALID_MAP_SYMBOLS, c))
		terminate("Non valid symbols in map file");
	if (c == 'w')
		return (1);
	if (c == 'c')
		return (2);
	if (c == 'a')
		return (3);
	if (c == 'd')
		return (4);
	return (0);
}

static void		get_map_line(t_wolf3d *wolf, char *s, int *i)
{
	int x;

	if (*i == wolf->map->h)
		terminate("Check your map (more strings)");
	if (ft_strlen(s) != wolf->map->w)
		terminate("Check your map (different length string)");
	x = 0;
	while (x < wolf->map->w)
	{
		wolf->map->grid[*i][x] = parse_char(s[x]);
		x++;
	}
	(*i)++;
}

void				read_map(char *f_name, t_wolf3d *wolf)
{
	char	*s;
	int		got;
	int		i;
	int		fd;

	errno = 0;
	i = 0;
	if ((fd = open(f_name, O_RDONLY)) == -1)
		terminate("An error occured while reading");
	while ((got = get_next_line(fd, &s)) == 1)
	{
		if (wolf->map->h == 0)
			get_map_w_h(wolf, s);
		else if (wolf->player->pos.x == -1)
			get_player_pos(wolf, s);
		else
			get_map_line(wolf, s, &i);
		free(s);
	}
	close(fd);
	if (i != wolf->map->h)
		terminate("Check your map (less strings)");
	if (got == -1)
		terminate("Read error");
	ft_validator(wolf);
}
