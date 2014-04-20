/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:39:51 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:36:03 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;

	len = ft_strlen((char *)s1);
	cpy = (char *)malloc(len * sizeof(char) + 1);
	if (cpy)
		return (ft_strcpy(cpy, s1));
	return (NULL);
}
