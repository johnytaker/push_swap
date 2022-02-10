/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/10 19:53:24 by iugolin          ###   ########.fr       */
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

t_list	*append_id(t_list **lst, char **data, int size)
{
	int		i;
	int		j;
	int		*arr;
	t_list	*ptr;

	i = 0;
	j = 0;
	arr = bubble_sort_id(int_arr_create(data, size), size);
	while (arr[i])
	{
		ptr = *lst;
		while (ptr->next)
		{
			if (ptr->data == data[i])
			{
				ptr->id = i;
				break ;
			}
			ptr = ptr->next;
		}
		i++;
	}
	return (*lst);
}