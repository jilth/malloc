/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:19:33 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:38:56 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		len_str;
	int		i;

	len_str = ft_strlen(s2);
	i = 0;
	if (s2 == NULL || *s2 == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (ft_strncmp(s1 + i , s2, len_str) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
