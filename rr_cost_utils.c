/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_cost_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:10:13 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/20 18:00:25 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	reverse_rotate_a_cost(t_stack *stack_a, t_list *b_node)
// {
// 	t_list	*a;
// 	int		i;

// 	i = 0;
// 	a = stack_a->head;
// 	stack_a->len = lstsize(&a);
// 	while (a->id < b_node->id)
// 	{
// 		i++;
// 		a = a->next;
// 	}
// 	i = stack_a->len - i;
// 	return (i);
// }

// int	reverse_rotate_b_cost(t_stack *stack_b, t_list *b_node)
// {
// 	t_list	*b;
// 	int		i;

// 	i = 0;
// 	b = stack_b->head;
// 	stack_b->len = lstsize(&b);
// 	while (b->id != b_node->id)
// 	{
// 		i++;
// 		b = b->next;
// 	}
// 	i = stack_b->len - i;
// 	return (i);
// }

int	reverse_rotate_a_cost(t_stack *stack_a, int b_id)
{
	t_list	*a;
	int		len;
	int		a_id;

	a = stack_a->head;
	len = stack_a->len;
	a_id = b_id + 1;
	while (a && a->id < b_id && a_id != b_id)
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
