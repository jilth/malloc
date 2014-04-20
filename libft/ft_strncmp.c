/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:21:37 by noumazza          #+#    #+#             */
/*   Updated: 2013/11/30 15:49:44 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			if ((unsigned char)s1[i] < (unsigned char)s2[i])
				return (-1);
			else
				return (1);
		}
		else if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
