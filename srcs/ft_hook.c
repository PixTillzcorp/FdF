/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:14:57 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:14:59 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_expose_hook(t_fdf *win)
{
	ft_calc_coord(win);
	return (0);
}

void	redraw(t_fdf *win)
{
	ft_bzero(win->data, FEN_HIGHT * FEN_WIDTH * 4);
	ft_calc_coord(win);
}

void	ft_projection(t_fdf *win)
{
	if (win->pro == ISO)
		win->pro = PARA;
	else if (win->pro == PARA)
		win->pro = ISO;
	redraw(win);
}

int		ft_key(int k_in, t_fdf *win)
{
	if (k_in == 53)
		ft_quit(win);
	if (k_in == 69 || k_in == 24)
		ft_zoom_inc(win);
	if (k_in == 78 || k_in == 27)
		ft_zoom_dec(win);
	if (k_in == 123)
		ft_move_l(win);
	if (k_in == 124)
		ft_move_r(win);
	if (k_in == 126)
		ft_move_u(win);
	if (k_in == 125)
		ft_move_d(win);
	if (k_in == 35)
		ft_projection(win);
	if (k_in == 30)
		ft_increase_h(win);
	if (k_in == 33)
		ft_decrease_h(win);
	if (k_in == 4)
		ft_switch_legend(win);
	if (k_in == 31)
		ft_reset_settings(win);
	return (0);
}
