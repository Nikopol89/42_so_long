/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:21:27 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:35 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_init_events(t_events *events)
{
	static int	i;

	events->life = 1;
	events->win = 0;
	events->money = 0;
	events->sfx = 0;
	events->exit = 0;
	events->moves = 0;
	if (!i)
	{
		events->mouse = 0;
		i++;
	}
}

void	ft_reset(t_core *core)
{
	int	i;

	i = -1;
	core->player.x = core->player.x_backup;
	core->player.y = core->player.y_backup;
	core->tex_player.fx_dir = EAST;
	ft_init_events(&core->events);
	while (core->map[++i])
		ft_strlcpy(core->map[i], core->map_backup[i], core->parser.w + 1);
}

static void	ft_window_size_check(t_core *core)
{
	mlx_get_screen_size(
		core->mlx, &core->parser.screen_w, &core->parser.screen_h);
	if (core->frame.w > core->parser.screen_w
		|| core->frame.h > core->parser.screen_h)
		ft_perror(ERR_MAPWINSIZE);
}

int	ft_init(int argc, char **argv, t_core *core)
{
	if (!ft_parser(argc, argv, core))
		return (0);
	ft_init_events(&core->events);
	core->mlx = mlx_init();
	ft_init_textures(core);
	core->frame.w = core->parser.w * 32;
	core->frame.h = core->parser.h * 32;
	ft_window_size_check(core);
	core->frame.img = mlx_new_image(core->mlx, core->frame.w, core->frame.h);
	core->frame.addr = mlx_get_data_addr(
			core->frame.img, &core->frame.bpp,
			&core->frame.size_line, &core->frame.endian);
	core->win = mlx_new_window(
			core->mlx, core->frame.w, core->frame.h, "so_long");
	return (1);
}
