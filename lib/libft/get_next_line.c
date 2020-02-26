/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <cstripeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:15:28 by cstripeb          #+#    #+#             */
/*   Updated: 2019/05/11 16:02:48 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_data	*get_fd(const int fd, t_list **list)
{
	t_list *tmp;
	t_data smp;

	tmp = *list;
	while (tmp && tmp->content && ((t_data *)tmp->content)->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		smp.fd = fd;
		smp.str = NULL;
		smp.str_len = 0;
		if (!(tmp = ft_lstnew(&smp, sizeof(smp))))
		{
			ft_strdel(&smp.str);
			return (NULL);
		}
		ft_lstadd(list, tmp);
		*list = tmp;
	}
	return ((t_data *)(tmp->content));
}

static int		get_line(char **line, t_data *data, int flag)
{
	size_t	l;
	char	*tmp;

	l = flag ? (size_t)(ft_strchr(data->str, flag) - data->str)
		: data->str_len;
	if (!flag && l == 0)
	{
		return (0);
	}
	tmp = NULL;
	if (!(*line = ft_strnew(l)))
		return (-1);
	*line = ft_strncpy(*line, data->str, l);
	tmp = data->str;
	data->str = ft_strdup(data->str + l + 1);
	ft_strdel(&tmp);
	if (!data->str)
		return (-1);
	data->str_len -= l + flag / 10;
	return (1);
}

static int		accum(t_data *data, char *new, size_t l)
{
	char *tmp;

	if (!data->str)
		if (!(data->str = ft_strnew(0)))
			return (0);
	tmp = data->str;
	data->str = ft_strjoin(data->str, new);
	ft_strdel(&tmp);
	if (!data->str)
		return (0);
	data->str_len += l;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*deskriptors;
	t_data			*tmp;
	char			buf[BUFF_SIZE + 1];
	size_t			sim_read;

	if (fd < 0 || !line || read(fd, NULL, 0) || BUFF_SIZE < 1)
		return (-1);
	if (!(tmp = get_fd(fd, &deskriptors)))
		return (-1);
	if (tmp->str && ft_strchr(tmp->str, '\n'))
		return (get_line(line, tmp, NL));
	while ((sim_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[sim_read] = '\0';
		if (!accum(tmp, buf, sim_read))
			return (-1);
		if (ft_strchr(tmp->str, '\n'))
			break ;
	}
	if (ft_strchr(tmp->str, '\n'))
		return (get_line(line, tmp, NL));
	return (get_line(line, tmp, NONL));
}
