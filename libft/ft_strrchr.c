/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:19 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:23:27 by noumazza         ###   ########.fr       */
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
