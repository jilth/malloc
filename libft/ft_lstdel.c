/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 14:07:19 by noumazza          #+#    #+#             */
/*   Updated: 2013/11/30 15:11:26 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*list_next;

	if ((*alst)->next != NULL)
		list = (*alst);
	while (list_next != NULL)
	{
		list_next = list->next;
		ft_lstdelone(&list, del);
		list = list_next;
	}
	*alst = NULL;
}
