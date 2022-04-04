/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:05:11 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/02 23:00:56 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **lst)
{
	t_list	*head;
	t_list	*tail;

	tail = *lst;
	head = (*lst)->next;
	while (tail->next)
		tail = tail->next;
	tail->next = *lst;
	tail->next->next = NULL;
	*lst = head;
}

void	do_rotate_bonus(t_list **lst)
{
	if (*lst && ((*lst)->next))
	{
		rotate(lst);
		// print_op(op_name);
	}
}

void	rotate_ab_bonus(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a && (*lst_a)->next)
		&& (*lst_b && (*lst_b)->next))
	{
		rotate(lst_a);
		rotate(lst_b);
		// print_op("rr");
	}
}
