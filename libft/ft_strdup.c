/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:18 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:18 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *s1)

{
	char	*cpy;
	int		len;

	len = ft_strlen((char *)s1);
	cpy = (char *)malloc(len * sizeof(char) + 1);
	if (cpy)
		return (ft_strcpy(cpy, s1));
	return (NULL);
}
