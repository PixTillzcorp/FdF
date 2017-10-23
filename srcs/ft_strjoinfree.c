/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:16:19 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:16:21 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_strjoinfree(char *left, char *right, char free_num)
{
	char	*out;

	out = ft_strjoin(left, right);
	if (free_num == 'l' || free_num == 'b')
		free(left);
	if (free_num == 'r' || free_num == 'b')
		free(right);
	return (out);
}
