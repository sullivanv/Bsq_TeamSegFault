/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgradebsq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 06:21:37 by suvitiel          #+#    #+#             */
/*   Updated: 2016/08/24 06:26:25 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq	ft_upgrade_bsq(t_bsq bsq)
{
	int i;
	int j;

	i = bsq.sol.i;
	j = bsq.sol.j;
	while (i < bsq.sol.i + bsq.sol.value)
	{
		while (j < bsq.sol.j + bsq.sol.value)
		{
			bsq.tab[i][j].number = bsq.plein;
			j++;
		}
		j = bsq.sol.j;
		i++;
	}
	return (bsq);
}
