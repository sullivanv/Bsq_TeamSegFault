/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 07:43:54 by suvitiel          #+#    #+#             */
/*   Updated: 2016/08/24 20:07:06 by hanguelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_case	*ft_init_line(t_case *line, int *i, int j, char *str)
{
	int x;

	x = 0;
	while (j < *i)
	{
		line[x].number = str[j];
		j++;
		x++;
	}
	line[x].number = '\0';
	return (line);
}

t_case	**ft_init_tab(char *str, int count, int *i)
{
	int		x;
	int		j;
	t_case	**tab;

	x = 0;
	*i = 0;
	if ((tab = (t_case**)malloc((sizeof(tab) * count) + 1)) == NULL)
		exit(-1);
	while (x < count)
	{
		while (str[*i] == '\n' && str[*i])
			*i = *i + 1;
		j = *i;
		while (str[*i] != '\n' && str[*i])
			*i = *i + 1;
		if ((tab[x] = (t_case*)malloc(sizeof(t_case) * (*i - j) + 1)) == NULL)
			exit(-1);
		tab[x] = ft_init_line(tab[x], i, j, str);
		x++;
	}
	tab[x] = 0;
	return (tab);
}

t_case	**ft_split_whitespaces(char *str)
{
	int i;
	int count;
	int first;

	i = 0;
	count = 0;
	first = 0;
	while (str[i])
	{
		while (str[i] == '\n' && str[i])
			i++;
		while (str[i] != '\n' && str[i])
		{
			if (first == 0)
				count++;
			first = 1;
			i++;
		}
		first = 0;
	}
	return (ft_init_tab(str, count, &i));
}
