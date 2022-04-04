/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:30:44 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/02 22:57:20 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **lst)
{
	t_list	*tmp_last;
	t_list	*previus;
	t_list	*stack;

	stack = *lst;
	tmp_last = stack;
	while (tmp_last->next)
	{
		previus = tmp_last;
		tmp_last = tmp_last->next;
	}
	tmp_last->next = stack;
	previus->next = NULL;
	*lst = tmp_last;
}

void	do_reverse_rotate_bonus(t_list **lst)
{
	if (*lst && (*lst)->next)
	{
		reverse_rotate(lst);
		// print_op(op_name);
	}
}

void	reverse_rotate_ab_bonus(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a && (*lst_a)->next)
		&& (*lst_b && (*lst_b)->next))
	{
		reverse_rotate(lst_a);
		reverse_rotate(lst_b);
		// print_op("rrr");
	}
}
