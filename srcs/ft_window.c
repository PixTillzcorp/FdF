#include "../includes/fdf.h"

static void	ft_win_start(t_fdf *win)
{
	if (!(win->mlx = mlx_init()))
		ft_error("mlx init failed", 0);
	if (!(win->win = mlx_new_window(win->mlx, FEN_WIDTH, FEN_HIGHT, "FdF")))
		ft_error("mlx new window failed", 0);
	win->pad = 1;
	win->pro = ISO;
	win->pad_h = 1;
	win->move_lr = 0;
	win->move_ud = 0;
	win->map_w = 0;
	win->legend = ON;
	if (!(win->img = mlx_new_image(win->mlx, FEN_WIDTH, FEN_HIGHT)))
		ft_error("mlx new image failed", 0);
	if (!(win->data = mlx_get_data_addr(win->img, &(win->color),\
	&(win->size), &(win->endian))))
		ft_error("mlx get data addr failed", 0);
	win->map = ft_init_map(win);
}

void		ft_fdf(t_fdf *win)
{
	ft_win_start(win);
	ft_calc_coord(win);
	mlx_hook(win->win, 2, (1L << 0), ft_key, win);
	mlx_expose_hook(win->win, ft_expose_hook, win);
	mlx_loop(win->mlx);
}