NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCDIR = ./src
FILES = main.c \
	init.c init_textures.c \
	input.c input_mov.c \
	parser.c parser_valid.c parser_utils.c get_next_line.c \
	raster.c raster_paint.c raster_paint_tileset.c \
	garbage_collectors.c
SRC = $(addprefix $(SRCDIR)/,$(FILES))
OBJ = ${SRC:.c=.o}

LDIR = ./lib
LFTDIR = $(LDIR)/libft
LPRINTFDIR = $(LDIR)/ft_printf
LMLXDIR = $(LDIR)/mlx
LFT = libft.a
LPRINTF = libftprintf.a
LMLX = libmlx.dylib
LIBS = -L$(LFTDIR) -L$(LPRINTFDIR) -lft -lftprintf $(LMLX)

all: $(NAME)

$(NAME): $(OBJ) | libraries
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

libraries: | $(LFT) $(LPRINTF) $(LMLX)

$(LFT):
	make -C $(LFTDIR)

$(LPRINTF):
	make -C $(LPRINTFDIR)

$(LMLX):
	make -C $(LMLXDIR)
	cp $(LMLXDIR)/$@ .

clean:
	rm -f $(NAME) $(OBJ)

fclean: clean
	make fclean -C $(LFTDIR)
	make fclean -C $(LPRINTFDIR)
	make clean -C $(LMLXDIR)
	rm $(LMLX);

re: clean all