/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:22:49 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:37:17 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_s;
	size_t	i;

	i = 0;
	new_s = (char *)malloc(size * sizeof(char));
	if (new_s)
	{
		while (i <= size)
		{
			new_s[i] = '\0';
			i++;
		}
		return (new_s);
	}
	return (NULL);
}
