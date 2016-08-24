/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 04:53:10 by suvitiel          #+#    #+#             */
/*   Updated: 2016/08/24 05:04:12 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_case	ft_count_left_top(t_bsq bsq, int i, int j)
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
	return (bsq.tab[ibase][jbase]);
}

void	ft_print_matrice(t_bsq bsq)
{
	int i = 0;
	int j = 0;

	while (i < bsq.size_i)
	{
		while (j < bsq.size_j)
		{
			if (bsq.tab[i][j].number == bsq.obstacle)
			{
				ft_putchar('\t');
				ft_putchar(bsq.tab[i][j].number);
				ft_putchar('\t');
			}
			else
			{
				ft_putchar('\t');
				ft_putchar(bsq.tab[i][j].number);
				ft_putchar(',');
				ft_putchar(' ');
				ft_putnbr(bsq.tab[i][j].left);
				ft_putchar(',');
				ft_putchar(' ');
				ft_putnbr(bsq.tab[i][j].top);
				ft_putchar('\t');
			}
			j++;
		}
		ft_putchar('\n');
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

int	ft_find_the_biggest(int i, int j, t_bsq bsq)
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
			break;
	}
	ft_putstr("Le plus grand carre est de taille: ");
	ft_putnbr(carre);
	ft_putstr(" et commence en position :");
	ft_putnbr(i);
	ft_putstr(",");
	ft_putnbr(j);
	ft_putchar('\n');
	return (carre);
	//	exit(0);
	//	return (carre);
}

void	ft_main_algo(t_bsq bsq)
{
	int i;
	int j;
	int carremax;
	int i_carre;
	int j_carre;

	i = 0;
	j = 0;
	carremax = 1;
	i_carre = 0;
	j_carre = 0;
	while (i < bsq.size_i)
	{
		while (j < bsq.size_j)
		{
			if (bsq.tab[i][j].number != bsq.plein)
			{
				//				if (carremax <= ft_find_the_biggest(bsq.tab, i, j, bsq.size_i, bsq.size_j))
				carremax = ft_find_the_biggest(i, j, bsq);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_matrix(t_bsq bsq)
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
				bsq.tab[i][j] = ft_count_left_top(bsq, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	ft_print_matrice(bsq);
	ft_main_algo(bsq);
}

// moins petite map
int main()
{
	t_bsq	bsq;
	t_case	**tab;

	bsq.size_i = 7;
	bsq.size_j = 6;
	bsq.obstacle = '1';
	bsq.vide = '0';

	tab = (t_case**)malloc(sizeof(t_case*) * bsq.size_i);
	int i = 0;
	while (i < bsq.size_i)
	{
		tab[i] = (t_case*)malloc(sizeof(t_case) * bsq.size_j);
		i++;
	}
	tab[0][0].number = '1';
	tab[0][1].number = '0';
	tab[0][2].number = '0';
	tab[0][3].number = '0';
	tab[0][4].number = '0';
	tab[0][5].number = '0';
	tab[1][0].number = '0';
	tab[1][1].number = '0';
	tab[1][2].number = '0';
	tab[1][3].number = '0';
	tab[1][4].number = '0';
	tab[1][5].number = '0';
	tab[2][0].number = '0';
	tab[2][1].number = '0';
	tab[2][2].number = '0';
	tab[2][3].number = '0';
	tab[2][4].number = '0';
	tab[2][5].number = '0';
	tab[3][0].number = '0';
	tab[3][1].number = '0';
	tab[3][2].number = '0';
	tab[3][3].number = '0';
	tab[3][4].number = '0';
	tab[3][5].number = '0';
	tab[4][0].number = '0';
	tab[4][1].number = '0';
	tab[4][2].number = '0';
	tab[4][3].number = '0';
	tab[4][4].number = '0';
	tab[4][5].number = '1';
	tab[5][0].number = '0';
	tab[5][1].number = '0';
	tab[5][2].number = '0';
	tab[5][3].number = '0';
	tab[5][4].number = '0';
	tab[5][5].number = '0';
	tab[6][0].number = '0';
	tab[6][1].number = '0';
	tab[6][2].number = '0';
	tab[6][3].number = '0';
	tab[6][4].number = '0';
	tab[6][5].number = '0';
	//	ft_putstr("ok\n");
	bsq.tab = tab;
	ft_matrix(bsq);
}
