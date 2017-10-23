#include "../includes/fdf.h"

void	ft_putstr(const char *str)
{
	size_t i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
