/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_cost_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:59:28 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/20 18:00:29 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a_cost(t_stack *stack_a, int b_id)
{
	t_list	*a;
	int		i;
	int		a_id;

	i = 0;
	a = stack_a->head;
	a_id = b_id + 1;
	while (a && a->id < b_id && a_id != b_id)
	{
		i++;
		a = a->next;
	}
	return (i);
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
