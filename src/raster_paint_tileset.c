/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster_paint_tileset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 02:08:01 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:08:02 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_paint_tileset_east(
	t_img *frame, t_img *tex, int frame_x, int frame_y)
{
	int		x;
	int		y;
	int		offset_x;
	int		line;
	char	*addr;

	addr = tex->addr + (tex->bpp / 8 * tex->w / TILESET * (tex->fx - 1));
	offset_x = frame_x;
	line = 0;
	y = -1;
	while (++y < tex->h)
	{
		x = -1;
		while (++x < tex->w / TILESET)
		{
			ft_pixel_put(frame, frame_x, frame_y, *(unsigned int *)addr);
			frame_x++;
			addr += tex->bpp / 8;
		}
		frame_x = offset_x;
		frame_y++;
		addr = tex->addr + (tex->bpp / 8 * tex->w / TILESET * (tex->fx - 1))
			+ tex->size_line * ++line;
	}
}

static void	ft_paint_tileset_west(
	t_img *frame, t_img *tex, int frame_x, int frame_y)
{
	int		x;
	int		y;
	int		offset_x;
	int		line;
	char	*addr;

	addr = tex->addr + (tex->bpp / 8 * tex->w / TILESET * (tex->fx - 1));
	offset_x = frame_x;
	line = 0;
	y = -1;
	while (++y < tex->h)
	{
		frame_x += 32;
		x = 32;
		while (--x > 0)
		{
			ft_pixel_put(frame, frame_x, frame_y, *(unsigned int *)addr);
			frame_x--;
			addr += tex->bpp / 8;
		}
		frame_x = offset_x;
		frame_y++;
		addr = tex->addr + (tex->bpp / 8 * tex->w / TILESET * (tex->fx - 1))
			+ tex->size_line * ++line;
	}
}

void	ft_paint_tileset(t_img *frame, t_img *tex, int frame_x, int frame_y)
{
	if (tex->fx_dir == EAST)
		ft_paint_tileset_east(frame, tex, frame_x, frame_y);
	if (tex->fx_dir == WEST)
		ft_paint_tileset_west(frame, tex, frame_x, frame_y);
}
