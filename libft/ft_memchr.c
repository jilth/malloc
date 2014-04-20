/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:17 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:17 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*temp;

	if (n != 0)
	{
		temp = (const unsigned char*)s;
		while (n > 0)
		{
			if (*temp++ == (unsigned char)c)
				return ((void *)(temp - 1));
			n--;
		}
	}
	return (NULL);
}
