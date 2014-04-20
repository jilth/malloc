/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:16 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:16 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_lstadd_endlst(t_list *lst, t_list *new)
{
	t_list		*tmp;

	if ((lst) == NULL)
		return (new);
	else
	{
		tmp = lst;
		while (tmp->next != NULL)
		{
			(tmp) = (tmp)->next;
		}
		(tmp)->next = new;
	}
	return (lst);
}

{
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
	t_list		*lst_tmp;
	t_list		*tmp;

	lst_tmp = NULL;
	while (lst != NULL)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (!tmp)
			return (NULL);
		tmp = (*f)(lst);
		lst_tmp = ft_lstadd_endlst(lst_tmp, tmp);
		lst = lst->next;
	}
	return (lst_tmp);
}
