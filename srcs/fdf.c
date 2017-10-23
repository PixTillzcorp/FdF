/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:14:16 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:14:20 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int argc, char **argv)
{
	t_fdf	win;

	if (argc < 2)
		ft_error("Enter a map !", 1);
	else if (argc > 2)
		ft_error("Too much args", 1);
	else if (!ft_check_ext(argv[1]))
		ft_error("Wrong file type", 1);
	win.file = argv[1];
	ft_fdf(&win);
	return (0);
}
