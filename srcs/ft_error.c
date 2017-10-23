/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:13:18 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/12 13:13:24 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_error(const char *msg, int usage)
{
	ft_putstr("FdF : ");
	ft_putstr(msg);
	ft_putchar('\n');
	if (usage)
		ft_putstr("usage : FdF [file.fdf]\n");
	exit(EXIT_FAILURE);
}

int		ft_check_ext(const char *path)
{
	int	i;

	i = 0;
	if (path)
		i = ft_strlen(path);
	else
		ft_error("Null arg", 0);
	while (path[i] != '.' && i > 0)
		i--;
	if (i < 0)
		return (0);
	if (!ft_strcmp((char *)(path + i), ".fdf"))
		return (1);
	else
		return (0);
}

void	ft_perror(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
