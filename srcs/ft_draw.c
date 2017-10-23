/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:14:46 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:14:49 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_draw_point(t_fdf *win, int x, int y, int color)
{
	ft_memcpy(&win->data[(x * 4) + (y * win->size)], (const void *)&(color),\
	(size_t)(sizeof(int)));
}

static void		ft_slow_increase(t_bresenham *bres, t_fdf *win)
{
	int			i;
	int			color;

	color = 0x00FFFF00;
	bres->cumul = bres->dx / 2;
	i = 1;
	while (i <= bres->dx)
	{
		bres->x += bres->xinc;
		bres->cumul += bres->dy;
		if (bres->cumul >= bres->dx)
		{
			bres->cumul -= bres->dx;
			bres->y += bres->yinc;
		}
		if (ft_check_x(bres->x) && ft_check_y(bres->y))
			ft_draw_point(win, bres->x, bres->y, bres->color);
		i++;
	}
}

static void		ft_high_increase(t_bresenham *bres, t_fdf *win)
{
	int			i;
	int			color;

	color = 0x00FFFF00;
	bres->cumul = bres->dy / 2;
	i = 1;
	while (i <= bres->dy)
	{
		bres->y += bres->yinc;
		bres->cumul += bres->dx;
		if (bres->cumul >= bres->dy)
		{
			bres->cumul -= bres->dy;
			bres->x += bres->xinc;
		}
		if (ft_check_x(bres->x) && ft_check_y(bres->y))
			ft_draw_point(win, bres->x, bres->y, bres->color);
		i++;
	}
}

static void		ft_draw_line(t_fdf *win, t_points *p1, t_points *p2)
{
	t_bresenham	*bres;

	bres = ft_bres_build(p1, p2, win->max_z);
	if (bres->dx > bres->dy)
		ft_slow_increase(bres, win);
	else
		ft_high_increase(bres, win);
	free(bres);
}

void			ft_draw(t_fdf *win)
{
	int			x;
	int			y;

	y = 0;
	while (y < win->map_h)
	{
		x = 0;
		while (x < win->map_w)
		{
			if (x < win->map_w - 1)
				ft_draw_line(win, win->map[y][x], win->map[y][x + 1]);
			if (y < win->map_h - 1)
				ft_draw_line(win, win->map[y][x], win->map[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	if (win->legend == ON)
		ft_legend(win);
}
