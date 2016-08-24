/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 04:19:23 by suvitiel          #+#    #+#             */
/*   Updated: 2016/08/24 04:41:54 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_case
{
    char number;
    int left;
    int top;
}               t_case;

typedef struct s_bsq
{
    int     size_i;
    int     size_j;
    t_case  **tab;
    char    obstacle;
    char    plein;
    char    vide;
}               t_bsq;

#endif
