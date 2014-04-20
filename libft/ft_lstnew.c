/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: longuyen <longuyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 13:36:07 by longuyen          #+#    #+#             */
/*   Updated: 2014/02/02 15:32:29 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	if (content)
	{
		new_elem->content = malloc(content_size);
		ft_memcpy(new_elem->content, content, content_size);
		new_elem->content_size = content_size;
	}
	else
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
	}
	new_elem->next = NULL;
	return (new_elem);
}
