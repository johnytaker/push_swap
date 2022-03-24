/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:00:08 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/24 18:01:55 by iugolin          ###   ########.fr       */
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

void	triple_sort_a(t_stack *stack_a)
{
	if (stack_a->len < 3 && stack_a->head->id > stack_a->head->next->id)
	{
		do_swap(&stack_a->head, "sa");
		exit(EXIT_SUCCESS);
	}
	else if (stack_a->len < 3 && stack_a->head->id < stack_a->head->next->id)
		exit(EXIT_SUCCESS);
	if (stack_a->head->id == stack_a->max_id)
		do_rotate(&stack_a->head, "ra");
	if (stack_a->head->next->id == stack_a->max_id)
		do_reverse_rotate(&stack_a->head, "rra");
	if (stack_a->head->id > stack_a->head->next->id)
		do_swap(&stack_a->head, "sa");
}

void	fifth_sort(t_info *info)
{
	t_list	*ptr_a;
	t_list	*ptr_b;
	int		i;

	ptr_a = info->a->head;
	ptr_b = info->b->head;
	i = 1;
	while (ptr_a->id != i && i < 3)
	{
		ptr_a = ptr_a->next;
		if (ptr_a->id == i)
		{
			push_b(&ptr_a, &ptr_b);
			i++;
		}
	}
	triple_sort_a(info->a);
	push_a(&info->a->head, &info->b->head);
	push_a(&info->a->head, &info->b->head);
}
