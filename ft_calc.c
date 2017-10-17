#include "fdf.h"

static void	ft_calc(t_fdf *win, t_points *point)
{
	if (win->pro == ISO)
	{
		point->new_x = win->pad * ((point->x) - (point->y))\
		+ FEN_WIDTH / 2 + win->move_lr;
		point->new_y = win->pad * ((point->x) + (point->y)) / 2 -\
		win->pad_h * (point->z + win->pad_h)\
		+ FEN_HIGHT / 4 + win->move_ud;
	}
	else if (win->pro == PARA)
	{
		point->new_x = win->pad * ((point->x - (point->z))) / 2\
		+ FEN_WIDTH / 2 + win->move_lr;
		point->new_y = win->pad * (point->y + point->z)\
		+ FEN_HIGHT / 3 + win->move_ud;
	}
}

void		ft_calc_coord(t_fdf *win)
{
	int x;
	int y;

	y = 0;
	while (y < win->map_h)
	{
		x = 0;
		while (x < win->map_w)
			ft_calc(win, win->map[y][x++]);
		y++;
	}
	ft_draw(win);
}

static int	ft_paint(int p_1, int p_2, int max_z)
{
	if (((p_1 + p_2) * 500) > 500 * max_z)
		return ((int)(0xFFFFFF));
	else if (((p_1 + p_2) * 500) >= 50 * max_z && ((p_1 + p_2) * 500) < 200 * max_z)
		return ((int)(0x25FF50));
	else if (((p_1 + p_2) * 500) >= 10 * max_z && ((p_1 + p_2) * 500) < 50 * max_z)
		return ((int)(0xFFFF00));
	else if (((p_1 + p_2) * 500) < 10 * max_z)
		return ((int)(0x0041FF));
	else
		return ((int)(0xAD4F09));
}

t_bresenham	*ft_bres_build(t_points *p_1, t_points *p_2, int max_z)
{
	t_bresenham *bres;

	bres = malloc(sizeof(t_bresenham));
	bres->x = p_1->new_x;
	bres->y = p_1->new_y;
	bres->dx = p_2->new_x - p_1->new_x;
	bres->dy = p_2->new_y - p_1->new_y;
	bres->xinc = (bres->dx > 0 ? 1 : -1);
	bres->yinc = (bres->dy > 0 ? 1 : -1);
	bres->dx = ft_abs(bres->dx);
	bres->dy = ft_abs(bres->dy);
	bres->delta_e = (bres->dx > bres->dy ? bres->dx : -(bres->dy)) / 2;
	bres->color = ft_paint(p_1->z, p_2->z, max_z);
	return (bres);
}
