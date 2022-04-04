/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:25:44 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/02 23:04:07 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **lst)
{
	t_list	*tmp_node;

	tmp_node = (*lst)->next;
	if ((*lst)->next->next)
		(*lst)->next = (*lst)->next->next;
	else
		(*lst)->next = NULL;
	tmp_node->next = *lst;
	*lst = tmp_node;
}

void	do_swap_bonus(t_list **lst)
{
	if (*lst && ((*lst)->next))
	{
		swap(lst);
		// print_op(op_name);
	}
}

void	swap_ab_bonus(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a && (*lst_a)->next)
		&& (*lst_b && (*lst_b)->next))
	{
		swap(lst_a);
		swap(lst_b);
		// print_op("ss");
	}
}
