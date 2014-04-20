/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:17 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:17 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char			*dst;
	const char		*src;

	dst = (char *)s1;
	src = (const char *)s2;
	if (src > dst || dst > src + n)
		ft_memcpy(dst, src, n);
	else
	{
		dst += n;
		src += n;
		while (n-- > 0)
			*--dst = *--src;
	}
	return (dst);
}
