.PHONY: clean, fclean, re, all

.SUFFIXES:

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

VPATH = includes:srcs

NAME = fdf

SRCC =	fdf.c ft_calc.c ft_draw.c ft_check.c ft_error.c ft_hook.c ft_legend.c	\
		ft_map.c ft_move.c ft_quit.c ft_window.c ft_zoom.c ft_putchar.c			\
		ft_putstr.c ft_itoa.c ft_strlen.c ft_atoi.c ft_strcmp.c ft_strdup.c		\
		ft_bzero.c ft_memcpy.c ft_memdel.c ft_strsplit.c ft_lstnew.c			\
		ft_lstdel.c ft_lst_push_back.c ft_lstlen.c get_next_line.c ft_strnew.c	\
		ft_size_int.c ft_memset.c ft_strsub.c ft_lstdelone.c ft_strchr.c		\
		ft_strjoinfree.c ft_strjoin.c ft_putnbr.c

SRCO =	$(SRCC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

#~~~~~~~~~~~~~MINILIBX~~~~~~~~~~~~~~

MLX = ./minilibx/
MLX_LIB = $(addprefix $(MLX),libmlx.a))
MLX_LNK = -L ./minilibx -l mlx -framework OpenGl -framework AppKit

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

all: $(MLX_LIB) $(NAME)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

all_re: mlx_re $(NAME)

mlx_re:
	@ make -C $(MLX) re

cleared:
	@ echo "$(YELLOW)$(FONT_NOIR)$(NAME) : $(RED).o files destruction\t\t[$(GREEN)\xe2\x9c\x94$(RED)]$(NORMAL)"

full_clear:
	@ echo "$(YELLOW)$(FONT_NOIR)$(NAME) : $(RED)executable file destruction\t[$(GREEN)\xe2\x9c\x94$(RED)]$(NORMAL)"

re_init:
	@ echo "$(BLUE)$(FONT_NOIR)Reseting $(NAME) }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(NORMAL)"

re_done:
	@ echo "$(BLUE)$(FONT_NOIR)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{ Reset Complete[$(GREEN)\xe2\x9c\x94$(BLUE)]$(NORMAL)"

%.o:%.c
	@ $(CC) $(CFLAGS) -c $<

$(MLX_LIB):
	@ make -C $(MLX)

$(NAME) : $(SRCO) fdf.h
	@ echo "$(PINK)$(FONT_NOIR).o successfully created\t\t\t[$(GREEN)\xe2\x9c\x94$(PINK)]$(NORMAL)"
	@ $(CC) -o $(NAME) $(SRCO) $(MLX_LNK) #$(LIB_PATH)libft.a
	@ echo "$(PINK)$(FONT_NOIR)Compilation of $(NAME)\t\t\t[$(GREEN)\xe2\x9c\x94$(PINK)]$(NORMAL)"
	
clean: cleared
	@ rm -f $(SRCO)
	@ make -C ./minilibx clean

fclean: full_clear clean
	@ rm -rf $(NAME)
	

re: re_init fclean all_re re_done
