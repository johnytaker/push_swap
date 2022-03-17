/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_cost_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:59:28 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/17 15:17:41 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a_cost(t_stack *stack_a, t_list *b_node)
{
	t_list	*a;
	int		i;

	i = 0;
	a = stack_a->head;
	while (a->id < b_node->id)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	rotate_b_cost(t_stack *stack_b, t_list *b_node)
{
	t_list	*b;
	int		i;

	b = stack_b->head;
	i = 0;
	while (b->id != b_node->id)
	{
		i++;
		b = b->next;
	}
	return (i);
}
