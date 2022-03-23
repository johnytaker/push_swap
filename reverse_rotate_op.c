/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:30:44 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/23 12:04:57 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **lst)
{
	t_list	*head;
	t_list	*tail;

	tail = *lst;
	head = last_node(*lst);
	while (tail->next->next)
		tail = tail->next;
	tail->next = NULL;
	head->next = *lst;
	*lst = head;
}

void	do_reverse_rotate(t_list **lst, char *op_name)
{
	if (*lst && (*lst)->next)
	{
		reverse_rotate(lst);
		print_op(op_name);
	}
}

void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a && (*lst_a)->next)
		&& (*lst_b && (*lst_b)->next))
	{
		reverse_rotate(lst_a);
		reverse_rotate(lst_b);
		print_op("rrr");
	}
}
