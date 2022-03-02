/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:05:11 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/25 13:21:37 by iugolin          ###   ########.fr       */
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

void	rotate_a(t_list **lst_a)
{
	if (*lst_a && ((*lst_a)->next))
	{
		rotate(lst_a);
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_list **lst_b)
{
	if (*lst_b && ((*lst_b)->next))
	{
		rotate(lst_b);
		write(1, "rb\n", 3);
	}
}

void	rotate_ab(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a && (*lst_a)->next)
		&& (*lst_b && (*lst_b)->next))
	{
		rotate(lst_a);
		rotate(lst_b);
		write(1, "rr\n", 3);
	}
}

