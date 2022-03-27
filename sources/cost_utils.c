/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:59:28 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/27 16:35:41 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	number_of_rotate_a(t_stack *stack_a,
	int b_id, int last_id, int cost)
{
	t_list	*a;

	a = stack_a->head;
	while (a)
	{
		if (b_id < a->id && b_id > last_id)
			break ;
		if (last_id == stack_a->min_id && b_id > a->id)
				cost++;
		else if (last_id != stack_a->min_id)
		{
			if (last_id == stack_a->max_id && b_id > a->id)
					cost++;
			else if (last_id != stack_a->max_id)
			{
				if (last_id < a->id)
					cost++;
				else if (last_id > a->id && b_id > a->id)
					cost++;
			}
		}
		a = a->next;
	}
	return (cost);
}

int	rotate_a_cost(t_stack *stack_a, int b_id, int last_id)
{
	return (number_of_rotate_a(stack_a, b_id, last_id, 0));
}

int	rotate_b_cost(t_stack *stack_b, int b_id)
{
	t_list	*b;
	int		i;

	b = stack_b->head;
	i = 0;
	while (b && b->id != b_id)
	{
		i++;
		b = b->next;
	}
	return (i);
}

int	reverse_rotate_a_cost(t_stack *stack_a, int b_id, int last_id)
{
	if (stack_a->len == 1)
		return (0);
	return (stack_a->len - rotate_a_cost(stack_a, b_id, last_id));
}

int	reverse_rotate_b_cost(t_stack *stack_b, int b_id)
{
	if (stack_b->len == 1)
		return (0);
	return (stack_b->len - rotate_b_cost(stack_b, b_id));
}
