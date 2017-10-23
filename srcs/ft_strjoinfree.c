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
