/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:09:50 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:36:43 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_s;

	i = 0;
	if (s && f)
	{
		new_s = (char *)malloc(ft_strlen(s) * sizeof(char));
		if (new_s)
		{
			while (s[i] != '\0')
			{
				new_s[i] = (*f)(i, s[i]);
				i++;
			}
			return (new_s);
		}
	}
	return (NULL);
}
