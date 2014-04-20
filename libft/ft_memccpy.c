/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:17 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:17 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*s1_pt;
	const char		*s2_pt;

	s2_pt = (char *)s2;
	s1_pt = (char *)s1;
	while (n-- > 0)
	{
		*s1_pt++ = *s2_pt++;
		if (*(s1_pt - 1) == c)
			return (s1_pt);
	}
	return (NULL);
}
