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
