/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:19 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:19 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
char	*ft_strrev(char *str)

{
	char	*s_cp;
	size_t	i;

	i = ft_strlen(str);
	s_cp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	s_cp[i] = '\0';
	i--;
	while (*str != '\0')
	{
		s_cp[i] = *str;
		i--;
		str++;
	}
	return (s_cp);
}
