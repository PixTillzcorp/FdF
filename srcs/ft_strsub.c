/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:16:30 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:16:32 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	if (!s)
		return (NULL);
	index = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (index < len)
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
