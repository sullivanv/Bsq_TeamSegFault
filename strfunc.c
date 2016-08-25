/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 01:52:29 by hanguelk          #+#    #+#             */
/*   Updated: 2016/08/25 02:01:04 by hanguelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putstderr(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		write(2, &str[i], 1);
		i++;
	}
}

int		ft_lenstructcase(t_case *tab)
{
	int	i;

	i = 0;
	while (tab[i].number != 0)
		i++;
	return (i);
}

t_bsq	get_thebadthegoodandtheugly(t_bsq bsm)
{
	int	i;

	i = ft_lenstructcase(bsm.tab[0]);
	bsm.vide = bsm.tab[0][i - 3].number;
	bsm.obstacle = bsm.tab[0][i - 2].number;
	bsm.plein = bsm.tab[0][i - 1].number;
	if ((bsm.size_i = ft_atoi(bsm.tab, i - 3)) <= 0)
	{
		bsm.tab = NULL;
		return (bsm);
	}
	return (bsm);
}
