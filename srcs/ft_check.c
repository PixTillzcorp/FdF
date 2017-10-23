/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:14:40 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:14:42 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_check_x(int x)
{
	if (x > 0 && x < FEN_WIDTH)
		return (1);
	return (0);
}

int		ft_check_y(int y)
{
	if (y > 0 && y < FEN_HIGHT)
		return (1);
	return (0);
}

int		ft_length(char **tab)
{
	int len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab[i])
	{
		while (tab[i])
			ft_memdel((void **)&tab[i++]);
		ft_memdel((void **)&tab[i]);
		free(tab);
		tab = NULL;
	}
}
