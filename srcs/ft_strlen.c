/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:16:22 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:16:24 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t		ft_strlen(const char *str)
{
	size_t size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}
