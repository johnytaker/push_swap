/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:59:28 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/23 11:46:23 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a_cost(t_stack *stack_a, int b_id, int last_id)
{
	t_list	*a;
	int		i;

	i = 0;
	a = stack_a->head;
	while (a)
	{
		if (b_id < a->id && (b_id > last_id || last_id == stack_a->max_id))
			return (i);

		if (last_id == stack_a->min_id)
		{
			if (b_id > a->id && b_id)
				i++;
		}
		else if (last_id != stack_a->min_id)
		{
			if (last_id == stack_a->max_id)
			{
				if (b_id > a->id)
					i++;
			}
			else if (last_id != stack_a->max_id)
			{
				if (last_id < a->id)
					i++;
				else if (last_id > a->id && b_id > a->id)
					i++;
			}
		}
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

int	reverse_rotate_a_cost_orig(t_stack *stack_a, int b_id)
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

int	reverse_rotate_a_cost(t_stack *stack_a, int b_id, int last_id)
{
	return(stack_a->len - rotate_a_cost(stack_a, b_id, last_id));
}

// {
// 	t_list	*a;
// 	int		i;
// 	i = 0;
// 	a = stack_a->head;

// 	while (a)
// 	{
// 		if (a->id > b_id && (b_id < last_id || last_id == 1))
// 			return (stack_a->len - i);

// 		if (a->id > b_id)
// 			i++;
// 		a = a->next;
// 	}
// 	return (stack_a->len - i);
// }

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
