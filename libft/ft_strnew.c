/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:19 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:19 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strnew(size_t size)
{
	char	*new_s;
	size_t	i;

	i = 0;
	new_s = (char *)malloc(size * sizeof(char));
	if (new_s)
	{
		while (i <= size)
		{
			new_s[i] = '\0';
		}
			i++;
		return (new_s);
	}
	return (NULL);
}
