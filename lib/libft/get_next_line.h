/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:16:52 by cstripeb          #+#    #+#             */
/*   Updated: 2019/10/09 16:42:44 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100
# define NL 10
# define NONL 0

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_data
{
	size_t		str_len;
	int			fd;
	char		*str;
}				t_data;

int				get_next_line(const int fd, char **line);

#endif
