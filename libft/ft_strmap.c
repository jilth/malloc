/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:50:23 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:36:32 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int			i;
	char		*new_s;

	if (s && f)
	{
		i = 0;
		new_s = (char *)malloc(ft_strlen(s) * sizeof(char));
		while (s[i] != '\0')
		{
			new_s[i] = (*f)(s[i]);
			i++;
		}
		return (new_s);
	}
	return (NULL);
}
