/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_def.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:20:50 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:08:58 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEF_H
# define SO_LONG_DEF_H
# define TILESET 28
# define KEY_W 0xd
# define KEY_A 0x0
# define KEY_S 0x1
# define KEY_D 0x2
# define KEY_R 0xf
# define KEY_ESC 0x35
# define KEY_SPACE 0x31
# define EAST 0
# define WEST 1
# define FRPFX 15

enum	e_err {
	ERR_UNDEF,
	ERR_ARGNO,
	ERR_ARGINV,
	ERR_ARGEXT,
	ERR_MAPH,
	ERR_MAPW,
	ERR_MAPSHAPE,
	ERR_MAPWALL,
	ERR_MAPCELL,
	ERR_MAPSPAWN,
	ERR_MAPEXIT,
	ERR_MAPMONEY,
	ERR_MAPWINSIZE,
};
const static char *const	g_errstr[] = {
	"Undefined",
	"Argument : Invalid amount of arguments",
	"Argument : Invalid argument",
	"Argument : Invalid file extension : Expected \"*.ber\"",
	"Map parsing : Invalid height",
	"Map parsing : Invalid width",
	"Map parsing : Invalid shape : Map must be rectangular",
	"Map parsing : Map is not surrounded by walls",
	"Map parsing : Invalid cell : Expected 01PEC",
	"Map parsing : Invalid amount of player spawn points : Expected 1",
	"Map parsing : Invalid amount of exit points : Expected 1",
	"Map parsing : Invalid amount of collectible points : Expected >= 1",
	"Map parsing : WARNING : Map size is bigger than screen size",
};

#endif