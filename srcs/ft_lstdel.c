/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:15:13 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:15:15 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*save;

	if (!(*alst))
		return ;
	tmp = *alst;
	while (tmp->next)
	{
		save = tmp->next;
		ft_lstdelone(&tmp, del);
		tmp = save;
	}
	ft_lstdelone(&tmp, del);
	(*alst) = NULL;
}
