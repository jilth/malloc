/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:19 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:19 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strstr(const char *s1, const char *s2)
{
	int		len_str;
	int		i;

	len_str = ft_strlen(s2);
	i = 0;
	if (s2 == NULL || *s2 == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
			return ((char *)s1 + i);
		if (ft_strncmp(s1 + i, s2, len_str) == 0)
		i++;
	}
	return (NULL);
}
