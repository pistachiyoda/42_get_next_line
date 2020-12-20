/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:54:36 by fmai              #+#    #+#             */
/*   Updated: 2020/12/21 01:44:31 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			make_line(char **save, int fd, char **line, int index)
{
	int i;

	i = 0;
	if (!(*line = (char *)malloc(sizeof(char) * (index + 1))))
		return (0);
	while (i < index)
	{
		(*line)[i] = save[fd][i];
		i++;
	}
	(*line)[i] = '\0';
	return (1);
}

int			make_save(char **save, int fd, int index)
{
	int		new_save_len;
	int		i;
	char	*tmp;

	new_save_len = ft_strlen(save[fd]) - index;
	if (!(tmp = (char *)malloc(sizeof(char) * new_save_len)))
		return (0);
	i = 0;
	while (i < new_save_len - 1)
	{
		tmp[i] = save[fd][index + i + 1];
		i++;
	}
	tmp[i] = '\0';
	free(save[fd]);
	save[fd] = tmp;
	return (1);
}

int			handle_save(char **save, int fd, char **line)
{
	int	i;

	if (!save[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((i = newline_index(save[fd])) != -1)
	{
		if (!make_line(save, fd, line, i))
			return (-1);
		if (!make_save(save, fd, i))
			return (-1);
		return (1);
	}
	*line = ft_strdup(save[fd]);
	free(save[fd]);
	save[fd] = NULL;
	return (0);
}

void		free_all(char *buf, char *save)
{
	free(buf);
	free(save);
}

int			get_next_line(int fd, char **line)
{
	int				buf_cnt;
	char			*buf;
	static char		*save[256];
	char			*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 256
	|| !(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	while ((buf_cnt = read(fd, buf, BUFFER_SIZE)))
	{
		if (buf_cnt == -1)
		{
			free_all(buf, save[fd]);
			return (-1);
		}
		if (!save[fd])
			save[fd] = ft_strdup("");
		tmp = ft_strnjoin(save[fd], buf, buf_cnt);
		free(save[fd]);
		save[fd] = tmp;
		if (newline_index(save[fd]) != -1)
			break ;
	}
	free(buf);
	return (handle_save(save, fd, line));
}
