/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:03:37 by noumazza          #+#    #+#             */
/*   Updated: 2014/01/09 12:10:09 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}
