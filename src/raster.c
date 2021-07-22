/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 02:07:52 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:54 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < img->w && y >= 0 && y < img->h && color < 0xff000000)
	{
		dst = img->addr + ((y * img->size_line) + (x * (img->bpp / 8)));
		*(unsigned int *)dst = color;
	}
}

static void	ft_raster_sfx(t_core *core)
{
	static int	cnt_frm;
	int			fx_start;
	int			fx_end;

	fx_start = 19;
	fx_end = 23;
	if (!cnt_frm)
		core->tex_player.fx = fx_start;
	cnt_frm++;
	if (!(cnt_frm % FRPFX))
		core->tex_player.fx++;
	ft_paint_tileset(&core->frame, &core->tex_player,
		core->player.x * 32, core->player.y * 32);
	if (core->tex_player.fx == fx_end)
	{
		cnt_frm = 0;
		core->tex_player.fx = 0;
		core->events.sfx = 0;
	}
}

static void	ft_raster_fx(t_core *core)
{
	static int	cnt_frm;
	int			fx_start;
	int			fx_end;

	fx_start = 1;
	fx_end = 9;
	if (!core->tex_player.fx)
		core->tex_player.fx = fx_start;
	if (core->tex_player.fx == fx_end)
		core->tex_player.fx = fx_start;
	if (!(cnt_frm % FRPFX))
		core->tex_player.fx++;
	cnt_frm++;
	if (cnt_frm == fx_end * FRPFX)
		cnt_frm = 0;
	ft_paint_tileset(&core->frame, &core->tex_player,
		core->player.x * 32, core->player.y * 32);
}

void	ft_raster(t_core *core)
{
	ft_paint_background(&core->frame, &core->tex_grnd);
	if (core->events.mouse)
	{
		mlx_mouse_get_pos(
			core->win, &core->events.mouse_x, &core->events.mouse_y);
		ft_paint_mouse(&core->frame, &core->tex_mouse, &core->events);
	}
	ft_paint_map(core);
	if (core->events.life && !core->events.sfx)
		ft_raster_fx(core);
	else if (core->events.sfx)
		ft_raster_sfx(core);
}
