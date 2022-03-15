/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/13 00:26:41 by iugolin          ###   ########.fr       */
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
static t_stack	*create_stack_a(char **data)
{
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (a)
		a->head = create_lst(data);
	// return (NULL);
	if (a->head)
		a->len = lstsize(&a->head);
	else
		free(a);
	return (a);
}

static t_stack	*create_stack_b(void)
{
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	if (b)
	{
		b->head = NULL;
		b->len = 0;
	}
	return (b);
}
t_info	*create_main_struct(char **data)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info)
	{
		info->a = create_stack_a(data);
		info->b = create_stack_b();
		if (!info->a && !info->b)
		{
			free(info);
		}
	}
	if (!info->a)
	{
		free(info);
		return (NULL);
	}
	if (!info->b)
	{
		free(info->a);
		free(info);
		return (NULL);
	}
	return (info);
}

t_list	*create_node(int data)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (new_elem)
	{
		new_elem->id = 0;
		new_elem->data = data;
		new_elem->score = 0;
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
