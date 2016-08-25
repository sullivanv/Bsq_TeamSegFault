/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 04:53:10 by suvitiel          #+#    #+#             */
/*   Updated: 2016/08/24 20:06:12 by hanguelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq		ft_count_left_top(t_bsq bsq, int i, int j)
{
	int countleft;
	int jbase;
	int ibase;
	int countop;

	jbase = j;
	ibase = i;
	countop = 1;
	countleft = 1;
	while (bsq.tab[i][j].number == bsq.vide && j > 0)
	{
		j--;
		if (bsq.tab[i][j].number == bsq.vide)
			countleft++;
	}
	bsq.tab[ibase][jbase].left = countleft;
	while (bsq.tab[i][jbase].number == bsq.vide && i > 0)
	{
		i--;
		if (bsq.tab[i][jbase].number == bsq.vide)
			countop++;
	}
	bsq.tab[ibase][jbase].top = countop;
	return (bsq);
}

int			ft_find_the_biggest(int i, int j, t_bsq bsq)
{
	int carre;
	int test_i;
	int test_j;

	carre = 1;
	test_i = i;
	test_j = j;
	while (bsq.tab[test_i][test_j].number != bsq.obstacle &&
			test_i + 1 < bsq.size_i && test_j + 1 < bsq.size_j)
	{
		if ((bsq.tab[test_i + 1][test_j + 1].left > (test_j + 1) - j) &&
				(bsq.tab[test_i + 1][test_j + 1].top > (test_i + 1) - i))
		{
			test_i++;
			test_j++;
			carre++;
		}
		else
			break ;
	}
	return (carre);
}

t_bsq		ft_eval_soluce(t_bsq bsq, int i, int j)
{
	int newvalue;

	newvalue = ft_find_the_biggest(i, j, bsq);
	if (newvalue > bsq.sol.value)
	{
		bsq.sol.value = newvalue;
		bsq.sol.i = i;
		bsq.sol.j = j;
	}
	else
	{
		if (bsq.sol.i + bsq.sol.j > i + j)
		{
			bsq.sol.value = newvalue;
			bsq.sol.i = i;
			bsq.sol.j = j;
		}
	}
	return (bsq);
}

t_bsq		ft_main_algo(t_bsq bsq)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < bsq.size_i)
	{
		while (j < bsq.size_j)
		{
			if (bsq.tab[i][j].number != bsq.obstacle)
			{
				if (bsq.sol.value <= ft_find_the_biggest(i, j, bsq))
					bsq = ft_eval_soluce(bsq, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (bsq);
}

void		ft_matrix(t_bsq bsq)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < bsq.size_i)
	{
		while (j < bsq.size_j)
		{
			if (bsq.tab[i][j].number == bsq.vide)
				bsq = ft_count_left_top(bsq, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	bsq = ft_main_algo(bsq);
	bsq = ft_upgrade_bsq(bsq);
	ft_put_bsq(bsq);
}
