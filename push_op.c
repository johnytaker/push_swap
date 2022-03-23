/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:23:24 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/23 12:06:13 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp_node;

	if (*lst_b)
	{
		tmp_node = (*lst_b)->next;
		push_front(lst_a, *lst_b);
		*lst_b = tmp_node;
		print_op("pa");
	}
}

void	push_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp_node;

	if (*lst_a)
	{
		tmp_node = (*lst_a)->next;
		push_front(lst_b, *lst_a);
		*lst_a = tmp_node;
		print_op("pb");
	}
}
