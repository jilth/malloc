/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:18 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:18 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		s1_size;
	size_t	i;

	if (!s2)
		return (s1);
	s1_size = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[s1_size + i] = s2[i];
		i++;
	}
	s1[s1_size + i] = '\0';
	return (s1);
}
