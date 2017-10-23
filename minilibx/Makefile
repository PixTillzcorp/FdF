#~~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~

FONT_NOIR = \033[40m
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
CYAN = \033[36m
GREY = \033[37m

NORMAL = \033[0m

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

re_mlx:
	@ echo "$(BLUE)$(FONT_NOIR)\nMLX }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(GREEN)"

end_re_mlx:
	@ echo "$(BLUE)$(FONT_NOIR)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{ MLX [$(GREEN)\xe2\x9c\x94$(BLUE)]\n$(NORMAL)"

$(NOM): $(OBJ)
	@ echo "$(GREEN)$(FONT_NOIR)~~~~~~~~~~~~~~~~~~"
	@ ar -r $(NOM) $(OBJ)
	@ echo "$(GREEN)$(FONT_NOIR)~~~~~~~~~~~~~~~~~~$(NORMAL)"
	@ echo "$(PINK)$(FONT_NOIR)mlx successfully created\t\t[$(GREEN)\xe2\x9c\x94$(PINK)]$(NORMAL)"
	@ ranlib $(NOM)

clean:
	@ rm -f $(NOM) $(OBJ) *~
	@ rm -f mlx_app

re: re_mlx clean all end_re_mlx
