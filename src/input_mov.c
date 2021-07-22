/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:21:16 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:35 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_input_mov_res(t_core *core)
{
	if (core->map[core->player.y][core->player.x] == 'C')
	{
		core->map[core->player.y][core->player.x] = '0';
		core->events.money++;
		if (core->events.money == core->parser.money)
			core->events.win = 1;
		core->events.sfx = 1;
	}
	if (core->map[core->player.y][core->player.x] == 'E' && core->events.win)
	{
		core->events.life = 0;
		ft_printf("- - -\nGAME OVER\n");
		ft_printf("Total moves: %d\n", core->events.moves);
		ft_printf("Collectibles %d/%d\nPress R to reset\n",
			core->events.money, core->parser.money);
	}
}

void	ft_input_mov(t_core *core, int key)
{
	if (key == KEY_W && core->map[core->player.y - 1][core->player.x] != '1')
	{
		core->player.y--;
		core->events.moves++;
	}
	if (key == KEY_A && core->map[core->player.y][core->player.x - 1] != '1')
	{
		core->player.x--;
		core->events.moves++;
		core->tex_player.fx_dir = WEST;
	}
	if (key == KEY_S && core->map[core->player.y + 1][core->player.x] != '1')
	{
		core->player.y++;
		core->events.moves++;
	}
	if (key == KEY_D && core->map[core->player.y][core->player.x + 1] != '1')
	{
		core->player.x++;
		core->events.moves++;
		core->tex_player.fx_dir = EAST;
	}
	ft_input_mov_res(core);
}

void	ft_mouse(t_core *core)
{
	if (!core->events.mouse)
	{
		mlx_mouse_hide(core->mlx, core->win);
		core->events.mouse = 1;
	}
	else
	{
		mlx_mouse_show(core->mlx, core->win);
		core->events.mouse = 0;
	}
}
