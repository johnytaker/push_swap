/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:25:44 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/05 21:06:14 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **lst)
{
	t_list	*tmp_node;

	tmp_node = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp_node->next = *lst;
	*lst = tmp_node;
}

void	swap_a(t_list **lst_a)
{
	if (*lst_a && (*lst_a)->next)
	{
		swap(lst_a);
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_list **lst_b)
{
	if (*lst_b && (*lst_b)->next)
	{
		swap(lst_b);
		write(1, "sb\n", 3);
	}
}

void	swap_ab(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a && (*lst_a)->next)
		&& (*lst_b && (*lst_b)->next))
	{
		swap_a(lst_a);
		swap_b(lst_b);
		write(1, "ss\n", 3);
	}
}

