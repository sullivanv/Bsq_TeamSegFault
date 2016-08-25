/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 04:19:23 by suvitiel          #+#    #+#             */
/*   Updated: 2016/08/25 02:00:37 by hanguelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define TMP_DATA_SIZE 131072

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

void			ft_matrix(t_bsq bsq);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nbr);
void			ft_put_bsq(t_bsq bsq);
t_bsq			ft_upgrade_bsq(t_bsq bsq);
t_bsq			parse_and_fill(char *buffer);
char			*read_map(char *filename, int fd);
char			*ft_strcat(char *dest, char *src);
char			*ft_realloc(void *ptr, int old_size, int nw_size);
t_case			**ft_split_whitespaces(char *str);
char			*ft_zero(char *buffer, int size);
void			ft_putstderr(char *str);
t_bsq			get_thebadthegoodandtheugly(t_bsq bsm);
int				ft_atoi(t_case **tab, int n);
int				ft_strlen(char *str);
int				ft_lenstructcase(t_case *tab);

#endif
