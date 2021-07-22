/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:21:20 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:30 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_keys(int key, t_core *core)
{
	if (!core->events.sfx)
	{
		if (key == KEY_R)
			ft_reset(core);
		if (core->events.life
			&& (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D))
			ft_input_mov(core, key);
	}
	if (key == KEY_SPACE)
		ft_mouse(core);
	if (key == KEY_ESC)
		core->events.exit = 1;
	return (1);
}

static int	ft_exit_btn(t_core *core)
{
	core->events.exit = 1;
	return (1);
}

int	ft_input(t_core *core)
{
	mlx_hook(core->win, 2, 1L << 0, ft_keys, core);
	mlx_hook(core->win, 17, 1L << 17, ft_exit_btn, core);
	return (0);
}
