/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 03:34:28 by hanguelk          #+#    #+#             */
/*   Updated: 2016/08/24 10:15:28 by hanguelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[l + i] = src[i];
		i++;
	}
	dest[l + i + 1] = '\0';
	return (dest);
}
