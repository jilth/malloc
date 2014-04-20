/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:04:54 by noumazza          #+#    #+#             */
/*   Updated: 2013/11/30 15:48:25 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		s1_size;
	size_t	i;

	if (!s2)
		return (s1);
	s1_size = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[s1_size + i] = s2[i];
		i++;
	}
	s1[s1_size + i] = '\0';
	return (s1);
}
