/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 05:23:24 by hanguelk          #+#    #+#             */
/*   Updated: 2016/08/24 20:08:31 by hanguelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		parse(t_case **tab, int n)
{
	int		i;
	int		signe;
	long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while ((tab[0][i].number == ' ') || (tab[0][i].number == '\t')
			|| (tab[0][i].number == '\r') || (tab[0][i].number == '\n'))
		i++;
	if (tab[0][i].number == '-')
	{
		signe = -1;
		i++;
	}
	else if (tab[0][i].number == '+')
		i++;
	if (tab[0][i].number < '0' || tab[0][i].number > '9')
		return (0);
	while ((tab[0][i].number >= '0' && tab[0][i].number <= '9' && i < n))
	{
		nb = nb * 10 + (tab[0][i].number - '0');
		i++;
	}
	return (nb * signe);
}

int		ft_atoi(t_case **tab, int n)
{
	return (parse(tab, n));
}
