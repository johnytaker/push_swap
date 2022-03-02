/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:00:08 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/02 19:21:31 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_less_then_median(t_list **lst_a, t_list **lst_b)
{
	int	median;
	int	size;

	size = lstsize(lst_a);
	median = find_median_id(lst_a);
	while (size--)
	{
		if ((*lst_a)->id < median)
			// && find_smallest_id(lst_a) != (*lst_a)->id
			// && find_biggest_id(lst_a) != (*lst_a)->id)
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
	}
}

void	push_b_more_then_median(t_list **lst_a, t_list **lst_b)
{
	int	median;
	int	size;

	size = lstsize(lst_a);
	median = find_median_id(lst_a);
	while (size--)
	{
		if ((*lst_a)->id > median
			&& find_smallest_id(lst_a) != (*lst_a)->id
			&& find_biggest_id(lst_a) != (*lst_a)->id)
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
	}
}

void	triple_sort_a(t_list **lst_a)
{
	int	min;
	int	max;
	int	median;

	min = find_smallest_id(lst_a);
	max = find_biggest_id(lst_a);
	median = find_median_id(lst_a);
	if ((*lst_a)->id > (*lst_a)->next->id
		&& (*lst_a)->id < last_node(*lst_a)->id)
		swap_a(lst_a);
	if ((*lst_a)->id > (*lst_a)->next->id
		&& (*lst_a)->id > last_node(*lst_a)->id)
		rotate_a(lst_a);
	if ((*lst_a)->id < (*lst_a)->next->id
		&& (*lst_a)->id > last_node(*lst_a)->id)
		reverse_rotate_a(lst_a);
}

void	push_all_b(t_list **lst_a, t_list **lst_b)
{
	int	count;

	count = lstsize(lst_a) - 1;
	while (count--)
	{
		if ((*lst_a)->id == find_median_id(lst_a))
			rotate_a(lst_a);
		else
			push_b(lst_a, lst_b);
	}
}