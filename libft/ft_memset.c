/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:17:50 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:34:29 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*temp;
	int		i;

	if (b && len > 0)
	{
		i = 0;
		temp = (char *)b;
		while (len > 0)
		{
			temp[i] = (char)c;
			len--;
			i++;
		}
	}
	return (b);
}
