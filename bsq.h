/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 04:19:23 by suvitiel          #+#    #+#             */
/*   Updated: 2016/08/24 06:25:27 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_case
{
	char	number;
	int		left;
	int		top;
}				t_case;

typedef struct	s_sol
{
	int		i;
	int		j;
	int		value;
}				t_sol;

typedef struct	s_bsq
{
	int		size_i;
	int		size_j;
	t_case	**tab;
	char	obstacle;
	char	plein;
	char	vide;
	t_sol	sol;
}				t_bsq;

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nbr);
void			ft_put_bsq(t_bsq bsq);
t_bsq			ft_upgrade_bsq(t_bsq bsq);

#endif
