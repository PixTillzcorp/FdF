#include "../includes/fdf.h"

void	ft_memdel(void **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}
