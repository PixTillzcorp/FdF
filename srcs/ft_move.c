/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:15:41 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:15:45 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_reset_settings(t_fdf *win)
{
	win->pad = 1;
	win->pro = ISO;
	win->pad_h = 1;
	win->move_lr = 0;
	win->move_ud = 0;
	win->legend = ON;
	redraw(win);
}

void	ft_move_l(t_fdf *win)
{
	if (win->move_lr > -3000)
		win->move_lr -= 5;
	redraw(win);
}

void	ft_move_r(t_fdf *win)
{
	if (win->move_lr < 3000)
		win->move_lr += 5;
	redraw(win);
}

void	ft_move_u(t_fdf *win)
{
	if (win->move_ud > -2000)
		win->move_ud -= 5;
	redraw(win);
}

void	ft_move_d(t_fdf *win)
{
	if (win->move_ud < 2000)
		win->move_ud += 5;
	redraw(win);
}
