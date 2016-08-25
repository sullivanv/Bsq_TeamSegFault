/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 04:57:16 by suvitiel          #+#    #+#             */
/*   Updated: 2016/08/24 20:09:40 by hanguelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_bsq(t_bsq bsq)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < bsq.size_i)
	{
		while (j < bsq.size_j)
		{
			if (bsq.tab[i][j].number == bsq.vide ||
				bsq.tab[i][j].number == bsq.plein ||
				bsq.tab[i][j].number == bsq.obstacle)
				ft_putchar(bsq.tab[i][j].number);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	my_put_unsigned(unsigned int nb)
{
	if (nb >= 10)
	{
		my_put_unsigned(nb / 10);
		my_put_unsigned(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	my_put_unsigned(nb);
}
