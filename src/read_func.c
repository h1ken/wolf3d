/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:02:33 by cstripeb          #+#    #+#             */
/*   Updated: 2020/02/28 19:37:35 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>

int	read_map(char *f_name, t_wolf3d *wolf)
{
	t_list	*lst;
	char	*s;
	int		got;
	int		fd;

	errno = 0;
	if ((fd = open(f_name, O_RDONLY)) == -1)
		terminate("An error occured while reading");
	if (!(wolf->map = (t_map *)ft_memalloc(sizeof(*(wolf->map)))))
		terminate("Malloc error for t_map");
	wolf->map->h = 0;
	wolf->map->w = 0;
	while ((got = get_next_line(fd, &s)) == 1)
	{
		if (wolf->map->h == 0)
		{
			if ((wolf->map->w = ft_atoi(s)) == 0 ||
							(wolf->map->h = ft_atoi(ft_strchr(s, ' ')) == 0))
				terminate("Check your map");
		}
		free(s);
	}
	if (got == -1)
		terminate("Read error");
	return (0);
}
