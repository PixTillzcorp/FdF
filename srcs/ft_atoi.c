/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:14:21 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:14:26 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_atoi(const char *str)
{
	int		result;
	size_t	i;
	char	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
	str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + sign * (str[i] - '0');
		i++;
	}
	return (result);
}
