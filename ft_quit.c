#include "fdf.h"

void	del(void *content, size_t size)
{
	size = 0;
	free(content);
	content = NULL;
}

void	ft_free_structure(t_points *point)
{
	free(point);
}

void	ft_free_line(t_points **line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		ft_free_structure(line[i]);
		i++;
	}
	free(line[i]);
	free(line);
	line[i] = NULL;
}

void	ft_quit(t_fdf *win)
{
	int		i;

	i = 0;
	while (win->map[i])
	{
		ft_free_line(win->map[i]);
		i++;
	}
	free(win->map[i]);
	free(win->map);
	win->map[i] = NULL;
	mlx_destroy_image(win->mlx, win->img);
	ft_bzero(win->data, FEN_HIGHT * FEN_WIDTH * 4);
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
}
