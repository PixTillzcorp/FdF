#include "../includes/fdf.h"

int		ft_lstlen(t_list *list)
{
	int x;

	x = 0;
	while (list)
	{
		x++;
		list = list->next;
	}
	return (x);
}
