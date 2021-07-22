/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collectors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:21:24 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:32 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_gc_map(t_core *core)
{
	int	i;

	i = -1;
	while (core->map[++i])
	{
		free (core->map[i]);
		free (core->map_backup[i]);
	}
	free (core->map);
	free (core->map_backup);
}

static void	ft_gc_mlx(t_core *core)
{
	mlx_destroy_image(core->mlx, core->frame.img);
	mlx_destroy_image(core->mlx, core->tex_player.img);
	mlx_destroy_image(core->mlx, core->tex_grnd.img);
	mlx_destroy_image(core->mlx, core->tex_money.img);
	mlx_destroy_image(core->mlx, core->tex_wall.img);
	mlx_destroy_image(core->mlx, core->tex_exit.img);
	mlx_destroy_image(core->mlx, core->tex_mouse.img);
	mlx_destroy_window(core->mlx, core->win);
}

void	ft_exit(t_core *core)
{
	ft_gc_mlx(core);
	ft_gc_map(core);
	exit (0);
}
