/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:54:58 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/08 17:56:10 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char		*mem;
	size_t		i;

	mem = (char *)malloc(size);
	i = 0;
	if (mem != 0)
	{
		while (i < size)
		{
			mem[i] = 0;
			i++;
		}
		return ((void *)mem);
	}
	return (NULL);
}
