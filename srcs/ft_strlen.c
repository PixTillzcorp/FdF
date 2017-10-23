#include "../includes/fdf.h"

size_t		ft_strlen(const char *str)
{
	size_t size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}
