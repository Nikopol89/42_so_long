/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 23:06:50 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:33 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_gnl_chain(char *tmp, char **line)
{
	char	*swap;

	swap = *line;
	*line = ft_strjoin(swap, tmp);
	if (!*line)
		return (0);
	free(swap);
	free(tmp);
	return (1);
}

static int	ft_gnl_engine(char *buf, char **line)
{
	static int	i;
	int			j;
	char		*tmp;

	j = 0;
	tmp = ft_calloc(4 + 1, sizeof(*tmp));
	if (!tmp)
		return (-1);
	while (i < 4)
	{
		if (buf[i] == '\n')
		{
			i++;
			if (!(ft_gnl_chain(tmp, line)))
				return (-1);
			return (0);
		}
		tmp[j++] = buf[i++];
	}
	if (!(ft_gnl_chain(tmp, line)))
		return (-1);
	i = 0;
	return (1);
}

static int	ft_gnl_v3(int fd, char **line, char *buf)
{
	int				read_size;
	int				status;

	read_size = 1;
	while (read_size >= 0)
	{
		if (read_size == 0)
			return (0);
		status = ft_gnl_engine(buf, line);
		if (status > 0)
		{
			ft_memset(buf, '\0', 4 + 1);
			read_size = read(fd, buf, 4);
		}
		if (!status)
			return (1);
		if (status < 0)
			return (-1);
	}
	return (-1);
}

int	ft_gnl(int fd, char **line)
{
	static char		buf[4 + 1];
	int				check;

	if (fd < 0 || fd > 256 || 4 <= 0 || !line)
		return (-1);
	*line = ft_calloc(1, sizeof(*line));
	if (!*line)
		return (-1);
	check = ft_gnl_v3(fd, line, buf);
	return (check);
}
