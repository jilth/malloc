/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:17 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:17 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memalloc(size_t size)

{
	char		*mem;
	size_t		i;

	mem = (char *)malloc(size);
	i = 0;
	if (mem != 0)
	{
		while (i < size)
		{
			mem[i] = 0;
			i++;
		}
		return ((void *)mem);
	}
	return (NULL);
}
