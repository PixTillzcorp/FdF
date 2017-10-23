#include "../includes/fdf.h"

char	*ft_strdup(char *str)
{
	char	*dest;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (0);
	while (i <= size)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
