/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:16:16 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:16:18 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dst;
	char *tmp;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	tmp = dst;
	while (*s1 != '\0')
		*tmp++ = *s1++;
	while (*s2 != '\0')
		*tmp++ = *s2++;
	*tmp = '\0';
	return (dst);
}
