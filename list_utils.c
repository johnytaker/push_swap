/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/13 16:45:21 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int data)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->id = NULL;
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

void	push_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_elem = last_node(*lst);
			last_elem->next = new;
		}
	}
}

void	push_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			new->next = *lst;
			*lst = new;
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

t_list	*append_id(t_list **lst, char **data, int size)
{
	int		i;
	int		*arr;
	t_list	*ptr;

	i = 0;
	arr = bubble_sort_id(int_arr_create(data, size), size);
	ptr = *lst;
	while (ptr->next)
	{
		i = 0;
		while (arr[i] && arr[i] != ptr->data)
			i++;
		if (arr[i] == ptr->data)
			ptr->id = i + 1;
		ptr = ptr->next;
	}
	return (*lst);
}
