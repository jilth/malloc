/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:33:49 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:36:20 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;

	if (s1 && s2)
	{
		new_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) \
						+ 1 * sizeof(char));
		new_s[0] = '\0';
		if (new_s)
		{
			ft_strcat(new_s, s1);
			ft_strcat(new_s, s2);
			return (new_s);
		}
	}
	return (NULL);
}
