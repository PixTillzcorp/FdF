#include "fdf.h"

void	ft_switch_legend(t_fdf *win)
{
	if (win->legend == ON)
		win->legend = OFF;
	else if (win->legend == OFF)
		win->legend = ON;
	redraw(win);
}

void	ft_legend(t_fdf *win)
{
	mlx_string_put(win->mlx, win->win, 20, 60, 0x00FF0000, "Map :");
	mlx_string_put(win->mlx, win->win, 70, 60, 0x00FF0000, win->file);
	mlx_string_put(win->mlx, win->win, 20, 80, 0x00FF0000,
		"Zoom : + and -");
	mlx_string_put(win->mlx, win->win, 20, 100, 0x00FF0000,
		"Change projection : P");
	mlx_string_put(win->mlx, win->win, 20, 120, 0x00FF0000,
		"Move : Arrows");
	mlx_string_put(win->mlx, win->win, 20, 140, 0x00FF0000,
		"Change altitude : [ and ]");
	mlx_string_put(win->mlx, win->win, 20, 160, 0x00FF0000,
		"Default settings : O");
	mlx_string_put(win->mlx, win->win, 20, 180, 0x00FF0000,
		"Hide legend : H");
	mlx_string_put(win->mlx, win->win, 20, 200, 0x00FF0000,
		"Zoom Level : ");
	if (win->pad == 1)
		mlx_string_put(win->mlx, win->win, 150, 200, 0x00FF0000,
			"Min");
	else if (win->pad < 75)
		mlx_string_put(win->mlx, win->win, 150, 200, 0x00FF0000,
			ft_itoa(win->pad));
	else
		mlx_string_put(win->mlx, win->win, 150, 200, 0x00FF0000,
			"Max");
}
