/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:21:25 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:33 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_init_teximg(t_core *core, t_img *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(
			core->mlx, path, &texture->w, &texture->h);
	texture->addr = mlx_get_data_addr(
			texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
	texture->fx = 0;
	texture->fx_dir = EAST;
}

static void	ft_init_textures_part_1(t_core *core)
{
	char	*path_player;
	char	*path_grnd;
	char	*path_money;

	path_player = "./textures/finn_tileset.xpm";
	path_grnd = "./textures/grass.xpm";
	path_money = "./textures/mushroom.xpm";
	ft_init_teximg(core, &core->tex_player, path_player);
	ft_init_teximg(core, &core->tex_grnd, path_grnd);
	ft_init_teximg(core, &core->tex_money, path_money);
}

static void	ft_init_textures_part_2(t_core *core)
{
	char	*path_wall;
	char	*path_exit;
	char	*path_mouse;

	path_wall = "./textures/tree.xpm";
	path_exit = "./textures/tent.xpm";
	path_mouse = "./textures/42.xpm";
	ft_init_teximg(core, &core->tex_wall, path_wall);
	ft_init_teximg(core, &core->tex_exit, path_exit);
	ft_init_teximg(core, &core->tex_mouse, path_mouse);
}

void	ft_init_textures(t_core *core)
{
	ft_init_textures_part_1(core);
	ft_init_textures_part_2(core);
}
