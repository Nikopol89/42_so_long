/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:21:07 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:38 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_engine(t_core *core)
{
	char	*moves;

	mlx_sync(1, core->frame.img);
	ft_raster(core);
	mlx_put_image_to_window(
		core->mlx, core->win, core->frame.img, 0, 0);
	moves = ft_itoa(core->events.moves);
	if (!moves)
		ft_exit(core);
	mlx_string_put(core->mlx, core->win, 5, 15, 0x00FFFFFF, moves);
	free(moves);
	mlx_sync(3, core->win);
	if (core->events.exit)
		ft_exit(core);
	return (0);
}

int	main(int argc, char **argv)
{
	t_core	core;

	if (!ft_init(argc, argv, &core))
		return (0);
	ft_input(&core);
	mlx_loop_hook(core.mlx, ft_engine, &core);
	mlx_loop(core.mlx);
	return (0);
}
