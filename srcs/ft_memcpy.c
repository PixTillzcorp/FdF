/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:15:34 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:15:36 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*d1;

	if (n == 0)
		return (dst);
	i = 0;
	s1 = (char *)src;
	d1 = (char *)dst;
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (dst);
}
