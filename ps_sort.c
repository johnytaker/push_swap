/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:00:08 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/22 01:53:47 by iugolin          ###   ########.fr       */
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
			rotate_a(&info->a->head);
		else if (info->a->median_id < info->a->head->id)
		{
			push_b(&info->a->head, &info->b->head);
			rotate_b(&info->b->head);
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

// void	triple_sort_a(t_stack *stack_a)
// {
// 	int	first;
// 	int	second;
// 	int	third;

// 	first = stack_a->head->id;
// 	second = stack_a->head->next->id;
// 	third = stack_a->head->next->next->id;
// 	if (first > second && second < third && first < third)
// 		swap_a(&stack_a->head);
// 	else if (first > second && second > third)
// 		|| (first > second && second > third)
// 		|| (first < second && second > third))
// 		swap_a(&stack_a->head);
// 	if (first > second && second < third && first > third)
// 		rotate_a(&stack_a->head);
// 	if (first < second && second > third)
// 		reverse_rotate_a(&stack_a->head);
// }

void	triple_sort_a(t_stack *stack_a)
{
	if (stack_a->head->id == stack_a->max_id)
		rotate_a(&stack_a->head);
	if (stack_a->head->next->id == stack_a->max_id)
		reverse_rotate_a(&stack_a->head);
	if (stack_a->head->id > stack_a->head->next->id)
		swap_a(&stack_a->head);
}

