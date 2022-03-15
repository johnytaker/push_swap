/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_count_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:10:13 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/14 19:50:51 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_a_count(t_stack *stack_a, int b_id)
{
	t_list	*a;
	int		i;

	i = 0;
	a = stack_a->head;
	stack_a->len = lstsize(&a);
	while (a->id < b_id)
	{
		i++;
		a = a->next;
	}
	i = stack_a->len - i;
	return (i);
}

int	reverse_rotate_b_count(t_stack *stack_b, int b_id)
{
	t_list	*b;
	int		i;

	i = 0;
	b = stack_b->head;
	stack_b->len = lstsize(&b);
	while (b != b_id)
	{
		i++;
		b = b->next;
	}
	i = stack_b->len - i;
	return (i);
}
