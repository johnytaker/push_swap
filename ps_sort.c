/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:00:08 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/16 13:02:13 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_all_b(t_list **lst_a, t_list **lst_b)
// {
// 	int	medeana;
// 	int	min;
// 	int	max;
// 	int	size;

// 	size = lstsize(lst_a);
// 	medeana = find_median_id(lst_a);
// 	min = find_smallest_id(lst_a);
// 	max = find_biggest_id(lst_a);
// 	while (size--)
// 	{
// 		if (medeana == (*lst_a)->id
// 			|| min == (*lst_a)->id
// 			|| max == ((*lst_a)->id))
// 			rotate_a(lst_a);
// 		else
// 			push_b(lst_a, lst_b);
// 	}
// }

void	push_all_b(t_list **lst_a, t_list **lst_b)
{
	int	medeana;
	int	min;
	int	max;
	int	size;

	size = lstsize(lst_a);
	medeana = find_medeana_id(lst_a);
	min = find_min_id(lst_a);
	max = find_max_id(lst_a);
	while (size--)
	{
		if (medeana == (*lst_a)->id
			|| min == (*lst_a)->id
			|| max == ((*lst_a)->id))
			rotate_a(lst_a);
		else if (medeana > (*lst_a)->id)
		{
			push_b(lst_a, lst_b);
			// rotate_b(lst_b);
		}
		else
			push_b(lst_a, lst_b);
	}
}

void	push_b_less_then_medeana(t_list **lst_a, t_list **lst_b)
{
	int	size;

	size = lstsize(lst_a);
	while (size--)
	{
		if ((*lst_a)->id >= find_medeana_id(lst_a)
			|| (*lst_a)->id == find_min_id(lst_a)
			|| (*lst_a)->id == find_max_id(lst_a))
			rotate_a(lst_a);
		else
			push_b(lst_a, lst_b);
	}
}

void	push_b_more_then_medeana(t_list **lst_a, t_list **lst_b)
{
	int	size;

	size = lstsize(lst_a);
	while (size--)
	{
		if ((*lst_a)->id <= find_medeana_id(lst_a)
			|| (*lst_a)->id == find_min_id(lst_a)
			|| (*lst_a)->id == find_max_id(lst_a))
			rotate_a(lst_a);
		else
			push_b(lst_a, lst_b);
	}
}

void	triple_sort_a(t_list **lst_a)
{
	int	min;
	int	max;
	int	median;

	min = find_min_id(lst_a);
	max = find_max_id(lst_a);
	median = find_medeana_id(lst_a);
	if (((*lst_a)->id > (*lst_a)->next->id
			&& (*lst_a)->next->id < last_node(*lst_a)->id)
		|| ((*lst_a)->id > (*lst_a)->next->id
			&& (*lst_a)->next->id > last_node(*lst_a)->id)
		|| ((*lst_a)->id < (*lst_a)->next->id
			&& (*lst_a)->next->id > last_node(*lst_a)->id))
		swap_a(lst_a);
	if ((*lst_a)->id > (*lst_a)->next->id
		&& (*lst_a)->next->id < last_node(*lst_a)->id)
		rotate_a(lst_a);
	if ((*lst_a)->id < (*lst_a)->next->id
		&& (*lst_a)->next->id > last_node(*lst_a)->id)
		reverse_rotate_a(lst_a);
}

void	sort_all(t_list **lst_a, t_list **lst_b)
{
	int	medeana;

	medeana = find_medeana_id(lst_a);
	while (*lst_b)
	{
		if ((*lst_b)->id < (*lst_a)->id
			&& (*lst_b)->id > last_node(*lst_a)->id)
			push_a(lst_a, lst_b);
		else if ((*lst_b)->next
			&& (*lst_a)->id < (*lst_b)->id
			&& (*lst_b)->id < (*lst_b)->next->id
			&& (*lst_b)->id < medeana)
				reverse_rotate_ab(lst_a, lst_b);
		else if ((*lst_b)->next
			&& (*lst_a)->id > (*lst_b)->id
			&& (*lst_b)->id > (*lst_b)->next->id
			&& (*lst_b)->id > medeana)
				rotate_ab(lst_a, lst_b);
		else if ((*lst_b)->id > medeana)
			rotate_a(lst_a);
		else
			reverse_rotate_a(lst_a);
	}
	while ((*lst_a)->id != 1)
		reverse_rotate_a(lst_a);
}
