/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:00:08 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/21 22:08:40 by iugolin          ###   ########.fr       */
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

// void	push_b_less_then_medeana(t_list **lst_a, t_list **lst_b)
// {
// 	int	size;

// 	size = lstsize(lst_a);
// 	while (size--)
// 	{
// 		if ((*lst_a)->id >= find_medeana_id(lst_a)
// 			|| (*lst_a)->id == find_min_id(lst_a)
// 			|| (*lst_a)->id == find_max_id(lst_a))
// 			rotate_a(lst_a);
// 		else
// 			push_b(lst_a, lst_b);
// 	}
// }

// void	push_b_more_then_medeana(t_list **lst_a, t_list **lst_b)
// {
// 	int	size;

// 	size = lstsize(lst_a);
// 	while (size--)
// 	{
// 		if ((*lst_a)->id <= find_medeana_id(lst_a)
// 			|| (*lst_a)->id == find_min_id(lst_a)
// 			|| (*lst_a)->id == find_max_id(lst_a))
// 			rotate_a(lst_a);
// 		else
// 			push_b(lst_a, lst_b);
// 	}
// }

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

// void	sort_all(t_list **lst_a, t_list **lst_b)
// {
// 	int	medeana;

// 	medeana = find_medeana_id(lst_a);
// 	while (*lst_b)
// 	{
// 		if ((*lst_b)->id < (*lst_a)->id
// 			&& (*lst_b)->id > last_node(*lst_a)->id)
// 			push_a(lst_a, lst_b);
// 		else if ((*lst_b)->next
// 			&& (*lst_a)->id < (*lst_b)->id
// 			&& (*lst_b)->id < (*lst_b)->next->id
// 			&& (*lst_b)->id < medeana)
// 				reverse_rotate_ab(lst_a, lst_b);
// 		else if ((*lst_b)->next
// 			&& (*lst_a)->id > (*lst_b)->id
// 			&& (*lst_b)->id > (*lst_b)->next->id
// 			&& (*lst_b)->id > medeana)
// 				rotate_ab(lst_a, lst_b);
// 		else if ((*lst_b)->id > medeana)
// 			rotate_a(lst_a);
// 		else
// 			reverse_rotate_a(lst_a);
// 	}
// 	while ((*lst_a)->id != 1)
// 		reverse_rotate_a(lst_a);
// }
