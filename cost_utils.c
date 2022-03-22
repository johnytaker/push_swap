/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:59:28 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/22 15:52:40 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a_cost(t_stack *stack, int id)
{
	t_list	*a;
	int		i;

	i = 0;
	a = stack->head;
	while (a
		&& ((a->id < id && a->next > id) || (a->id == stack->min_id && stack_a )
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	reverse_rotate_a_cost(t_stack *stack, int id)
{
	t_list	*a;
	int		len;

	a = stack->head;
	len = stack->len;
	while (a && a->id != id)
	{
		len--;
		a = a->next;
	}
	return (len);
}

