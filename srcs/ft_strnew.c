/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:16:25 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:16:27 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
