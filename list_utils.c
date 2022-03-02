/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/02 16:42:08 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int data)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->id = 0;
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

t_list	*last_node(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	push_back(t_list **lst, t_list *node)
{
	t_list	*last_elem;

	if (lst)
	{
		if (*lst == NULL)
			*lst = node;
		else
		{
			last_elem = last_node(*lst);
			last_elem->next = node;
		}
	}
}

void	push_front(t_list **lst, t_list *node)
{
	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = node;
			(*lst)->next = NULL;
		}
		else
		{
			node->next = *lst;
			*lst = node;
		}
	}
}

int	lstsize(t_list **lst)
{
	int	i;

	i = 0;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		i++;
	}
	return (i);
}
