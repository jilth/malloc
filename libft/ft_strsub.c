/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:19 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:27:53 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)

{
	char	*new_s;
	size_t	i;

	i = 0;
	if (s)
	{
		new_s = (char *)malloc(len + 1);
		if (new_s)
		{
			while (i < len)
			{
				new_s[i] = s[start + i];
				i++;
			}
			if (new_s[i] != '\0')
				new_s[i] = '\0';
			return (new_s);
		}
	}
	return (NULL);
}
