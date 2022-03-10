/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/10 20:57:09 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void find_score_main(t_info ptr)
// {
// 	reset_costs(ptr);

// 	while(node)
// 	{
// 		int cost = find_score(ptr);
// 		if cost < ptr->min_cost
// 			ptr->min_cost = cost;
// 			ptr->pop_ind = node->id;
// 	}
// }

void	allocate_stacks_struct(t_info *info)
{
	info->a = (t_stack *)malloc(sizeof(t_stack));
	info->b = (t_stack *)malloc(sizeof(t_stack));
}

t_list	*create_node(int data)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->id = 0;
	new_elem->data = data;
	new_elem->score = 0;
	new_elem->next = NULL;
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
