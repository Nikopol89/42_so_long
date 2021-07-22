/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:21:13 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:43 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_map_valid_spawns(t_parser *parser)
{
	if (parser->spawn != 1)
		return (ERR_MAPSPAWN);
	if (parser->exit != 1)
		return (ERR_MAPEXIT);
	if (!parser->money)
		return (ERR_MAPMONEY);
	return (0);
}

static void	ft_map_spawns_cnt(t_core *core, int i)
{
	int	j;

	j = -1;
	while (core->map[i][++j])
	{
		if (core->map[i][j] == 'P')
		{
			core->parser.spawn++;
			core->player.y = i;
			core->player.x = j;
		}
		if (core->map[i][j] == 'E')
			core->parser.exit++;
		if (core->map[i][j] == 'C')
			core->parser.money++;
	}
}

static int	ft_map_valid_main(t_core *core, int w)
{
	int	i;

	i = -1;
	while (core->map[++i])
	{
		if ((int)ft_strlen(core->map[i]) < w)
			return (ERR_MAPSHAPE);
		if (core->map[i][0] != '1' || core->map[i][w - 1] != '1')
			return (ERR_MAPWALL);
		if (!ft_map_valid_line(core->map[i], "01PEC"))
			return (ERR_MAPCELL);
		ft_map_spawns_cnt(core, i);
	}
	return (ft_map_valid_spawns(&core->parser));
}

int	ft_map_valid(t_core *core, int h)
{
	int	w;

	core->parser.spawn = 0;
	core->parser.exit = 0;
	core->parser.money = 0;
	if (h < 3)
		return (ERR_MAPH);
	w = ft_strlen(core->map[0]);
	if (w < 3)
		return (ERR_MAPW);
	if (!ft_map_valid_bounds(core->map[0], '1')
		|| !ft_map_valid_bounds(core->map[h - 1], '1'))
		return (ERR_MAPWALL);
	core->parser.w = w;
	core->parser.h = h;
	return (ft_map_valid_main(core, w));
}
