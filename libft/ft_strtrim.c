/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:19 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:19 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strtrim(char const *s)
{
	size_t		last_pos;
	char		*s2;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
	{
		s2 = ft_strnew(0);
		return (s2);
	}
	last_pos = ft_strlen(s) - 1;
	while (s[last_pos] == ' ' || s[last_pos] == '\n' || s[last_pos] == '\t')
		last_pos--;
	s2 = ft_strnew(last_pos + 1);
	if (s2 == NULL)
		return (s2);
	s2 = ft_strncpy(s2, s, last_pos + 1);
	return (s2);
}
