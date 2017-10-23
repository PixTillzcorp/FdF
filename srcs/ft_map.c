/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:15:32 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:15:34 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_points	*ft_newpoint(char *data, int y, int x, t_fdf *win)
{
	t_points	*point;

	if (!(point = (t_points *)malloc(sizeof(t_points))))
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = ft_atoi(data);
	if (point->z >= 5000 || point->z <= -5000)
		ft_error("points too high", 0);
	if (point->z > win->max_z)
		win->max_z = point->z;
	return (point);
}

static t_points	**ft_new_line(char *line, int y, t_fdf *win)
{
	t_points	**bigline;
	char		**tab;
	int			x;

	x = 0;
	if (!(bigline = malloc(sizeof(t_points *) * (ft_strlen(line) + 1))))
		return (NULL);
	tab = ft_strsplit(line, ' ');
	x = 0;
	while (tab[x])
	{
		bigline[x] = ft_newpoint(tab[x], y, x, win);
		x++;
	}
	if (x != win->map_w)
		ft_error("error map width", 0);
	bigline[x] = NULL;
	x = 0;
	while (tab[x])
		free(tab[x++]);
	free(tab);
	return (bigline);
}

static t_points	***ft_create_map(t_list *map, t_fdf *win)
{
	t_points	***tab;
	char		**tmp;
	int			y;

	y = 0;
	tmp = ft_strsplit(map->content, ' ');
	win->map_w = ft_length(tmp);
	ft_free_tab(tmp);
	if (!(tab = malloc(sizeof(t_points **) * ft_lstlen(map) + 1)))
		return (NULL);
	while (map)
	{
		if (map->content == NULL || ft_strlen(map->content) == 0)
			break ;
		tab[y] = ft_new_line(map->content, y, win);
		y++;
		map = map->next;
	}
	win->map_h = y;
	tab[y] = NULL;
	return (tab);
}

static t_list	*ft_create_list(int fd, t_list *map)
{
	char		*line;
	int			gnl;
	int			i;

	i = 0;
	line = ft_strdup("");
	while ((gnl = get_next_line(fd, &line)) != 0)
	{
		if (gnl == -1 || i >= 2000 || (char)(*line) == 0)
			ft_error("Invalid read or map too big", 0);
		ft_lst_push_back(&map, ft_lstnew(line, ft_strlen(line)));
		free(line);
		i++;
	}
	if (line)
		free(line);
	if (i == 0)
		ft_error("Empty map", 0);
	return (map);
}

t_points		***ft_init_map(t_fdf *win)
{
	int			fd;
	t_list		*map;
	t_points	***tab;

	if ((fd = open(win->file, O_RDONLY)) < 0)
		ft_perror("FdF");
	map = NULL;
	map = ft_create_list(fd, map);
	if (!(tab = ft_create_map(map, win)))
		ft_error("Error creating the map", 0);
	ft_lstdel(&map, del);
	free(map);
	if (close(fd) < 0)
		ft_error("close failed", 0);
	return (tab);
}
