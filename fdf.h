#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define ISO_CONST1 2
# define ISO_CONST2 2
# define FEN_WIDTH 1900
# define FEN_HIGHT 1200
# define ISO 1
# define PARA 0
# define ON 1
# define OFF 0

typedef struct		s_points
{
	int				x;
	int				y;
	int				z;
	int				new_x;
	int				new_y;
	int				color;

}					t_points;

typedef struct		s_bresenham
{
	int				dx;
	int				dy;
	int				cumul;
	int				x;
	int				y;
	int				xinc;
	int				yinc;
	int				delta_e;
	int				color;

}					t_bresenham;

typedef	struct		s_fdf
{
	char			*file; //path
	void			*mlx; //pointeur init
	void			*win; //pointeur sur fenetre
	char			*data; //pointeur sur data adrr
	void			*img; //pointeur sur l'image
	int				pro; //projection ISO || PARA
	int				size; //variable pour data addr
	int				endian; //variable pour data addr
	int				pad;
	int				pad_h;
	int				move_lr; //valeur decalage gauche droite
	int				move_ud; //valeur decalage haut bas
	t_points		***map; //coordonnees points
	int				map_h; //hauteur map
	int				map_w; //largeur map
	int				max_z; //hauteur max
	int				color; //couleur
	int				legend; //legend ON || OFF
}					t_fdf;

void				ft_fdf(t_fdf *win);

void				ft_calc_coord(t_fdf *win);
t_bresenham			*ft_bres_build(t_points *p_1, t_points *p_2, int max_z);

int					ft_check_x(int x);
int					ft_check_y(int y);
int					ft_length(char **tab);
void				ft_free_tab(char **tab);

void				ft_draw(t_fdf *win);

int					ft_error(const char *msg, int usage);
int					ft_check_ext(const char *path);
void				ft_perror(const char *msg);

int					ft_expose_hook(t_fdf *win);
void				ft_redraw(t_fdf *win);
void				ft_projection(t_fdf *win);
int					ft_key(int k_in, t_fdf *win);

t_points			***ft_init_map(t_fdf *win);

void				ft_switch_legend(t_fdf *win);
void				ft_legend(t_fdf *win);

void				ft_reset_settings(t_fdf *win);
void				ft_move_l(t_fdf *win);
void				ft_move_r(t_fdf *win);
void				ft_move_u(t_fdf *win);
void				ft_move_d(t_fdf *win);

void				ft_zoom_inc(t_fdf *win);
void				ft_zoom_dec(t_fdf *win);
void				ft_increase_h(t_fdf *win);
void				ft_decrease_h(t_fdf *win);

void				del(void *content, size_t size);
void				ft_free_structure(t_points *point);
void				ft_free_line(t_points **line);
void				ft_quit(t_fdf *win);

int					ft_expose_hook(t_fdf *win);
void				redraw(t_fdf *win);
void				ft_projection(t_fdf *win);
int					ft_key(int k_in, t_fdf *win);

#endif































