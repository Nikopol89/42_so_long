/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:20:24 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:09:01 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "so_long_def.h"
# include "../lib/mlx/mlx.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
	int		fx;
	int		fx_dir;
}			t_img;

typedef struct s_events
{
	int	life;
	int	win;
	int	money;
	int	sfx;
	int	exit;
	int	moves;
	int	mouse;
	int	mouse_x;
	int	mouse_y;
}		t_events;

typedef struct s_parser
{
	int	w;
	int	h;
	int	screen_w;
	int	screen_h;
	int	spawn;
	int	exit;
	int	money;
}		t_parser;

typedef struct s_player
{
	int	x;
	int	y;
	int	x_backup;
	int	y_backup;
}		t_player;

typedef struct s_core
{
	void		*mlx;
	void		*win;
	char		**map;
	char		**map_backup;
	t_img		frame;
	t_img		tex_player;
	t_img		tex_grnd;
	t_img		tex_wall;
	t_img		tex_money;
	t_img		tex_exit;
	t_img		tex_mouse;
	t_events	events;
	t_parser	parser;
	t_player	player;
}				t_core;

/*PARSER*/

int		ft_parser(int argc, char **argv, t_core *core);
int		ft_gnl(int fd, char **line);
void	ft_perror(int err);
int		ft_arg_check(int argc, char **argv);
int		ft_map_valid(t_core *core, int h);
int		ft_map_valid_bounds(char *str, char c);
int		ft_map_valid_line(char *str, char *c);

/*INIT*/

int		ft_init(int argc, char **argv, t_core *core);
void	ft_init_textures(t_core *core);
void	ft_reset(t_core *core);

/*GARBAGE COLLECTORS*/

void	ft_exit(t_core *core);
void	ft_gc_map(t_core *core);

/*RASTER*/

void	ft_raster(t_core *core);
void	ft_pixel_put(t_img *img, int x, int y, unsigned int color);
void	ft_paint_texture(t_img *frame, t_img *tex, int x, int y);
void	ft_paint_background(t_img *frame, t_img *tex);
void	ft_paint_map(t_core *core);
void	ft_paint_mouse(t_img *frame, t_img *tex, t_events *events);
void	ft_paint_tileset(t_img *frame, t_img *tex, int frame_x, int frame_y);

/*INPUT*/

int		ft_input(t_core *core);
void	ft_mouse(t_core *core);
void	ft_input_mov(t_core *core, int key);
void	ft_input_mov_res(t_core *core);

#endif