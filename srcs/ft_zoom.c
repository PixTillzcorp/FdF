/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:16:37 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:16:39 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_zoom_inc(t_fdf *win)
{
	if (win->pad < 75)
		win->pad += 1;
	redraw(win);
}

void	ft_zoom_dec(t_fdf *win)
{
	if (win->pad > 1)
	{
		win->pad -= 1;
		redraw(win);
	}
}

void	ft_increase_h(t_fdf *win)
{
	if (win->pad_h < 20)
		win->pad_h += 1;
	redraw(win);
}

void	ft_decrease_h(t_fdf *win)
{
	if (win->pad_h > 1)
	{
		win->pad_h -= 1;
		redraw(win);
	}
}
