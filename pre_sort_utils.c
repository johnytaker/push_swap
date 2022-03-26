/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:00:08 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/26 14:56:09 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_sort(t_stack *stack, char *op_name)
{
	if (stack->head->id > stack->head->next->id)
		do_swap(&stack->head, op_name);
}

void	triple_sort(t_stack *stack)
{
	if (stack->head->id == stack->max_id)
		do_rotate(&stack->head, "ra");
	if (stack->head->next->id == stack->max_id)
		do_reverse_rotate(&stack->head, "rra");
	if (stack->head->id > stack->head->next->id)
		do_swap(&stack->head, "sa");
}

static void	quad_sort(t_info *info)
{
	while (info->a->head->id != 1)
		do_rotate(&info->a->head, "ra");
	push_b(info);
	triple_sort(info->a);
	push_a(info);
}

static void	fifth_sort(t_info *info)
{
	while (info->b->len != 2)
	{
		if (info->a->head->id == 1 || info->a->head->id == 2)
			push_b(info);
		else
			do_rotate(&info->a->head, "ra");
	}
	if (info->b->head->id == 1 && info->a->head->id != 3)
		swap_ab(&info->a->head, &info->b->head);
	triple_sort(info->a);
	push_a(info);
	push_a(info);
	double_sort(info->a, "sa");
}

void	sort_small_numbers(t_info *info)
{
	if (info->a->len == 2)
		double_sort(info->a, "sa");
	else if (info->a->len == 3)
		triple_sort(info->a);
	else if (info->a->len == 4)
		quad_sort(info);
	else if (info->a->len == 5)
		fifth_sort(info);
}
