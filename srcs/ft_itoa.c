#include "../includes/fdf.h"

char		*ft_itoa(int n)
{
	size_t	i;
	char	*str;

	i = ft_size_int(n);
	str = ft_strnew(i);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	else
		n = -n;
	while (i >= 1 && str[i - 1] != '-')
	{
		str[--i] = -(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
