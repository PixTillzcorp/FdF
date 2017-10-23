#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

# define ISO_CONST1 2
# define ISO_CONST2 2
# define FEN_WIDTH 1900
# define FEN_HIGHT 1200
# define ISO 1
# define PARA 0
# define ON 1
# define OFF 0

# define BUFF_SIZE 4096
# define MAX_FD 4096
# define NEWLINE '\n'

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

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

//libft


void				ft_putnbr(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *left, char *right, char free_num);
char				*ft_strchr(const char *s, int c);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_size_int(int n);
char				*ft_strnew(size_t size);
int					fill_buff(int fd, char **stock, char **line);
int					get_next_line(const int fd, char **line);
int					stock_gestion(int fd, char **stock, char **line);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

size_t				ft_strlen(const char *str);
char				*ft_strdup(char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putstr(const char *str);
void				ft_putchar(char c);
void				ft_memdel(void **ap);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lst_push_back(t_list **lst, t_list *elem);
int					ft_lstlen(t_list *list);

//fdf

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
