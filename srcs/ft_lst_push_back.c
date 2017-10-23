/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:15:10 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:15:12 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_lst_push_back(t_list **lst, t_list *elem)
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = elem;
	else
	{
		tmp = *lst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = elem;
	}
}
