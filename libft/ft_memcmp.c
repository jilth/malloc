/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:17 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:17 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dst;
	size_t			i;

	if (n != 0)
	{
		src = (unsigned char*)s1;
		dst = (unsigned char*)s2;
		i = 0;
		while (i < n)
		{
			if (src[i] != dst[i])
				return (src[i] - dst[i]);
			i++;
		}
	}
	return (0);
}
