/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:00:08 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/24 20:17:56 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b(t_info *info)
{
	int	size;

	size = info->a->len;
	while (size--)
	{
		if (info->a->min_id == info->a->head->id
			|| info->a->median_id == info->a->head->id
			|| info->a->max_id == info->a->head->id)
			do_rotate(&info->a->head, "ra");
		else if (info->a->median_id < info->a->head->id)
		{
			push_b(&info->a->head, &info->b->head);
			do_rotate(&info->b->head, "rb");
			info->a->len--;
			info->b->len++;
		}
		else
		{
			push_b(&info->a->head, &info->b->head);
			info->a->len--;
			info->b->len++;
		}
	}
}

void	double_sort(t_stack *stack)
{
	if (stack->head->id > stack->head->next->id)
		do_swap(&stack->head, "sa");
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

void	fifth_sort(t_info *info)
{
	int		size;

	size = info->a->len;
	while (size--)
	{
		if (info->a->head->id == 1 || info->a->head->id == 2)
			push_b(&info->a->head, &info->b->head);
		else
			do_rotate(&info->a->head, "ra");
	}
	double_sort(info->b);
	triple_sort(info->a);
	push_a(&info->a->head, &info->b->head);
	push_a(&info->a->head, &info->b->head);
}

void	sort_small_numbers(t_info *info, int size)
{
	if (size == 2)
		double_sort(info->a);
	else if (size == 3)
		triple_sort (info->a);
	else if (size == 5)
		fifth_sort(info);
}

void	malloc_free(t_info *info)
{
	while
}
