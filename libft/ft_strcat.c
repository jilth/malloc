/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:42:22 by noumazza          #+#    #+#             */
/*   Updated: 2013/11/30 15:34:31 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	s1_size;
	int	i;

	if (!s2)
		return (s1);
	s1_size = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[s1_size + i] = s2[i];
		i++;
	}
	s1[s1_size + i] = '\0';
	return (s1);
}
