/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 11:35:33 by vtam              #+#    #+#             */
/*   Updated: 2016/11/02 19:37:41 by vtam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *current_list;

	if (!lst)
	{
		return (0);
	}
	new_list = f(lst);
	current_list = new_list;
	while (lst->next != NULL)
	{
		current_list->next = f(lst->next);
		current_list = current_list->next;
		lst = lst->next;
	}
	return (new_list);
}
