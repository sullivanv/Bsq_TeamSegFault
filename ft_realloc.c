/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:22:22 by hanguelk          #+#    #+#             */
/*   Updated: 2016/08/23 23:51:50 by hanguelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_zero(char *buffer, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		buffer[i] = '\0';
		i++;
	}
	return (buffer);
}

char	*ft_realloc(char *ptr, int old_size, int nw_size)
{
	char	*tmp;
	int		i;

	i = 0;
	if ((tmp = (char *)malloc(sizeof(char) * nw_size)) == NULL)
		exit(-1);
	tmp = ft_zero(tmp, nw_size);
	while (i < old_size)
	{
		tmp[i] = ptr[i];
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (tmp);
}
