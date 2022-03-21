/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:59:28 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/21 23:47:51 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a_cost(t_stack *stack_a, int b_id)
{
	t_list	*a;
	int		i;
	int		wished_id;

	i = 0;
	a = stack_a->head;
	wished_id = b_id + 1;
	while (a && a->id != wished_id)
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

int	reverse_rotate_a_cost(t_stack *stack_a, int b_id)
{
	t_list	*a;
	int		len;
	int		wished_id;

	a = stack_a->head;
	len = stack_a->len;
	wished_id = b_id + 1;
	while (a && a->id != wished_id)
	{
		len--;
		a = a->next;
	}
	return (len);
}

int	reverse_rotate_b_cost(t_stack *stack_b, int b_id)
{
	t_list	*b;
	int		len;

	b = stack_b->head;
	len = stack_b->len;
	while (b && b->id != b_id)
	{
		len--;
		b = b->next;
	}
	return (len);
}
