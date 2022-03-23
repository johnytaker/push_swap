/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:52:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/23 11:49:50 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (new_elem)
	{
		new_elem->id = 0;
		new_elem->value = value;
		new_elem->next = NULL;
	}
	return (new_elem);
}

t_list	*last_node(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
	}
	return (ptr);
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
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = *lst;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
