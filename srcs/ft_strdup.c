/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:16:13 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:16:15 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_strdup(char *str)
{
	char	*dest;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (0);
	while (i <= size)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
