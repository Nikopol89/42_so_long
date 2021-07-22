/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster_paint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:21:10 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:58 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_paint_texture(t_img *frame, t_img *tex, int frame_x, int frame_y)
{
	int		x;
	int		y;
	int		offset_x;
	int		line;
	char	*addr;

	addr = tex->addr;
	offset_x = frame_x;
	line = 0;
	y = -1;
	while (++y < tex->h)
	{
		x = -1;
		while (++x < tex->w)
		{
			ft_pixel_put(frame, frame_x, frame_y, *(unsigned int *)addr);
			frame_x++;
			addr += tex->bpp / 8;
		}
		frame_x = offset_x;
		frame_y++;
		addr = tex->addr + tex->size_line * ++line;
	}
}

void	ft_paint_background(t_img *frame, t_img *tex)
{
	int		x;
	int		y;

	y = 0;
	while (y < frame->h)
	{
		x = 0;
		while (x < frame->w)
		{
			ft_paint_texture(frame, tex, x, y);
			x += tex->w;
		}
		y += tex->h;
	}
}

void	ft_paint_map(t_core *core)
{
	int	x;
	int	y;

	y = -1;
	while (core->map[++y])
	{
		x = -1;
		while (core->map[y][++x])
		{
			if (core->map[y][x] == '1')
				ft_paint_texture(
					&core->frame, &core->tex_wall, x * 32, y * 32);
			if (core->map[y][x] == 'C')
				ft_paint_texture(
					&core->frame, &core->tex_money, x * 32, y * 32);
			if (core->map[y][x] == 'E')
				ft_paint_texture(
					&core->frame, &core->tex_exit, x * 32, y * 32);
		}
	}
}

void	ft_paint_mouse(t_img *frame, t_img *tex, t_events *events)
{
	int		x;
	int		y;

	x = events->mouse_x - (tex->w / 2);
	y = events->mouse_y - (tex->h / 2);
	ft_paint_texture(frame, tex, x, y);
}
