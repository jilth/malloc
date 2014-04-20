/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:16 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:16 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_bzero(void *s, size_t n)
	char	*temp;
{
	int		i;

	i = 0;
	temp = s;
	while (n != 0)
	{
		temp[i] = 0;
		i++;
		n--;
	}
}
