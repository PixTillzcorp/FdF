/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:16:28 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/23 15:16:29 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		nb_lines(const char *s, char c)
{
	int			count;
	int			insub;

	insub = 0;
	count = 0;
	while (*s != '\0')
	{
		if (insub == 1 && *s == c)
			insub = 0;
		else if (insub == 0 && *s != c)
		{
			insub = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static	int		nb_letters(const char *s, char c)
{
	size_t		len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		words;
	char		**tab;

	if (!s)
		return (NULL);
	i = 0;
	words = nb_lines(s, c);
	tab = (char **)malloc(sizeof(*tab) * (words + 1));
	if (tab == NULL)
		return (NULL);
	while (words)
	{
		while (*s == c && *s != 0)
			s++;
		tab[i] = ft_strsub(s, 0, nb_letters(s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + nb_letters(s, c);
		i++;
		words--;
	}
	tab[i] = NULL;
	return (tab);
}
