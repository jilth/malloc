/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:06:05 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:37:53 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*chr;
	char	c_conv;
	int		i;

	chr = NULL;
	c_conv = (char)c;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c_conv)
			chr = (char *)s + i;
	}
	if (c_conv == '\0')
		chr = (char *)s + i;
	if (chr == NULL)
		return (NULL);
	return (chr);
}
