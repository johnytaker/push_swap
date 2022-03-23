/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:28:26 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/23 22:52:33 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_nbr(int x, int y)
{
	if (x <= y)
		return (x);
	return (y);
}

static int	get_min_cost(int x, int y)
{
	if (x && y)
		return (min_nbr(x, y));
	else if (x)
		return (x);
	return (y);
}

static void	calc_costs(t_decisions *ptr, int r, int rr)
{
	ptr->cost = get_min_cost(r, rr);
	ptr->r = 0;
	ptr->rr = 0;
	if (ptr->cost == r)
		ptr->r = r;
	if (ptr->cost == rr)
		ptr->rr = rr;
}

static void	find_costs(t_info *info, int b_id)
{
	t_decisions	a_str;
	t_decisions	b_str;
	int			min_cost;

	calc_costs(&a_str,
		rotate_a_cost(info->a, b_id, last_node(info->a->head)->id),
		reverse_rotate_a_cost(info->a, b_id, last_node(info->a->head)->id));
		// reverse_rotate_a_cost(info->a, b_id));
	calc_costs(&b_str, rotate_b_cost(info->b, b_id),
		reverse_rotate_b_cost(info->b, b_id));
	min_cost = a_str.cost + b_str.cost;
	if (info->min_cost == DEFAULT_COST
		|| info->min_cost > min_cost)
	{
		reset_costs(info);
		info->min_cost = min_cost;
		info->pop_ind = b_id;
		info->ra_ct = a_str.r;
		info->rb_ct = b_str.r;
		info->rra_ct = a_str.rr;
		info->rrb_ct = b_str.rr;
	}
	else if (info->min_cost <= min_cost)
		return ;
}

void	find_costs_manager(t_info *info)
{
	t_list	*ptr;

	ptr = info->b->head;
	while (ptr)
	{
		find_costs(info, ptr->id);
		ptr = ptr->next;
		// print_found_cost(info);
	}
}
