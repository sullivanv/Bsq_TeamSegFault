/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 13:01:27 by hanguelk          #+#    #+#             */
/*   Updated: 2016/08/25 01:10:26 by hanguelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		check_valid_map(t_bsq bsm)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (bsm.tab[i])
	{
		while (bsm.tab[i][j].number != 0)
		{
			if (bsm.tab[i][j].number != bsm.vide &&
					bsm.tab[i][j].number != bsm.plein &&
					bsm.tab[i][j].number != bsm.obstacle)
				return (0);
			j++;
		}
		if (j != bsm.size_j)
			return (0);
		j = 0;
		i++;
	}
	if (i != bsm.size_i)
		return (0);
	return (1);
}

t_bsq	parse_and_fill(char *buffer)
{
	t_bsq	bsm;

	bsm.tab = ft_split_whitespaces(buffer);
	free(buffer);
	if (bsm.tab[1])
	{
		bsm.size_j = ft_lenstructcase(bsm.tab[1]);
		bsm = get_thebadthegoodandtheugly(bsm);
		if (bsm.tab != NULL)
		{
			bsm.tab = &(bsm.tab[1]);
			bsm.sol.value = 0;
			if (check_valid_map(bsm))
				return (bsm);
		}
	}
	ft_putstderr("map error\n");
	bsm.tab = NULL;
	return (bsm);
}

char	*read_map(char *filename, int fd)
{
	int		size;
	int		totalsize;
	char	*buffer;
	char	tmp2[TMP_DATA_SIZE];

	totalsize = 0;
	size = 0;
	if ((buffer = (char *)malloc(sizeof(char) * TMP_DATA_SIZE)) == NULL)
		exit(-1);
	buffer = ft_zero(buffer, TMP_DATA_SIZE);
	fd = (filename != NULL) ? open(filename, O_RDONLY) : 0;
	if (fd == -1)
		return (NULL);
	while ((size = read(fd, tmp2, TMP_DATA_SIZE)) > 0)
	{
		if (size == -1)
			return (NULL);
		tmp2[size] = '\0';
		totalsize += size;
		buffer = ft_realloc(buffer, ft_strlen(buffer), (totalsize + 1));
		buffer[totalsize] = '\0';
		ft_strcat(buffer, tmp2);
	}
	close(fd);
	return (buffer);
}

void	fillandcompute(char *buff)
{
	t_bsq bsq0;

	bsq0 = parse_and_fill(buff);
	if (bsq0.tab == NULL)
		return ;
	ft_matrix(bsq0);
}

int		main(int ac, char **ar)
{
	int		i;
	char	*buff;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			if ((buff = read_map(ar[i], 0)) != NULL)
				fillandcompute(buff);
			else
				ft_putstderr("map error\n");
			i++;
		}
	}
	else
	{
		if ((buff = read_map(NULL, 0)) == NULL)
			return (-1);
		fillandcompute(buff);
	}
	return (0);
}
