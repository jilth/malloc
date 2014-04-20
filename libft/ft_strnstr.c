/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:43:28 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:37:37 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t			len_str;
	size_t			i;

	len_str = ft_strlen(s2);
	i = 0;
	if (s2 == NULL || s2[i] == '\0')
		return ((char *)s1);
	if (len_str <= n)
	{
		while (s1[i] != '\0' && i < n)
		{
			if (ft_strncmp(s1 + i, s2, len_str) == 0)
				return ((char *)s1 + i);
			i++;
		}
	}
	return (NULL);
}
