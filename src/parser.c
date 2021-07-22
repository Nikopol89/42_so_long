/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:21:14 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:44 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_fd_check(char **argv, int *fd)
{
	int	err;

	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		err = errno;
		ft_putstr_fd("Error\n", 2);
		perror(strerror(err));
		return (0);
	}
	return (1);
}

static int	ft_map_save(char *line, t_core *core, int i)
{
	char	**tmp;
	int		j;

	j = -1;
	tmp = core->map;
	while (i && ++j <= i)
		tmp[j] = core->map[j];
	core->map = ft_calloc(i + 2, sizeof(*core->map));
	if (!core->map)
	{
		ft_gc_map(core);
		return (0);
	}
	j = -1;
	while (i && ++j <= i)
		core->map[j] = tmp[j];
	core->map[i] = line;
	if (i)
		free(tmp);
	return (1);
}

static int	ft_map_read(char **argv, int *cnt, t_core *core)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	if (!ft_fd_check(argv, &fd))
		return (0);
	while (ret > 0)
	{
		ret = ft_gnl(fd, &line);
		if (!ft_map_save(line, core, *cnt))
			return (0);
		*cnt += 1;
	}
	return (1);
}

static int	ft_map_backup(t_core *core, int cnt)
{
	int	i;

	i = -1;
	core->player.x_backup = core->player.x;
	core->player.y_backup = core->player.y;
	core->map_backup = ft_calloc(cnt, sizeof(*core->map_backup));
	while (core->map[++i])
	{
		core->map_backup[i] = ft_strdup(core->map[i]);
		if (!core->map_backup[i])
			return (0);
	}
	return (1);
}

int	ft_parser(int argc, char **argv, t_core *core)
{
	int	cnt;
	int	parser;

	cnt = 0;
	if (!ft_arg_check(argc, argv))
		return (0);
	if (!ft_map_read(argv, &cnt, core))
		return (0);
	parser = ft_map_valid(core, cnt);
	if (!ft_map_backup(core, cnt))
		return (0);
	if (parser)
	{
		ft_perror(parser);
		ft_gc_map(core);
		return (0);
	}
	return (1);
}
