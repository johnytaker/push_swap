/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:29 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/16 20:59:26 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_costs(t_info *info, t_list *node)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	min_r;
	int	min_rr;
	int	min_cost;
	int	rr;
	int	rrr;

	ra = rotate_a_cost(info->a, node);
	rb = rotate_b_cost(info->b, node);
	rra = reverse_rotate_a_cost(info->a, node);
	rrb = reverse_rotate_b_cost(info->b, node);
	if (ra > rb)
	{
		min_r = ra - rb;
		rr = ra - min_r;
		min_r += rr;
		rb = 0;
	}
	else
	{
		min_r = rb - ra;
		rr = rb - min_r;
		min_r += rr;
		ra = 0;
	}
	if (rra > rrb)
	{
		min_rr = rra - rrb;
		rrr = rra - min_rr;
		min_rr += rrr;
		rrb = 0;
	}
	else
	{
		min_rr = rrb - rra;
		rrr = rrb - min_rr;
		min_rr += rrr;
		rra = 0;
	}
	if (min_r < min_rr)
		min_cost = min_r;
	else
		min_cost = min_rr;
	// printf("%d | %d\n", min_cost, info->min_cost);
	if (info->min_cost == DEFAULT_COST)
		info->min_cost = min_cost;
	else if (min_cost < info->min_cost)
	{
		if (min_r < min_rr)
		{
			reset_costs(info);
			info->min_cost = min_cost;
			info->ra_ct = ra;
			info->rb_ct = rb;
			info->rr_ct = rr;
			info->pop_ind = node->id;
		}
		else
		{
			reset_costs(info);
			info->min_cost = min_cost;
			info->rra_ct = rra;
			info->rrb_ct = rrb;
			info->rrr_ct = rrr;
			info->pop_ind = node->id;
		}
	}
	else
		return ;
}

static void	find_costs_manager(t_info *info)
{
	t_list	*ptr;

	ptr = info->b->head;
	while (ptr)
	{
		find_costs(info, ptr);
		ptr = ptr->next;
	}
}

// void	do_operation(char *op_name, t_info *info)
// {
// 	if (op_name == "ra")
// 		rotate_a(&info->a->head);
// 	if (op_name == "rb")
// 		rotate_b(&info->b->head);
// 	if (op_name == "rra")
// 		reverse_rotate_a(&info->a->head);
// 	if (op_name == "rrb")
// 		reverse_rotate_b(&info->b->head);
// 	if (op_name == "rr")
// 		rotate_ab(&info->a->head, &info->b->head);
// 	if (op_name == "rrr")
// 		reverse_rotate_ab(&info->a->head, &info->b->head);
// }

static void	do_operations(t_info *info)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = info->a->head;
	ptr_b = info->b->head;
	if (info->ra_ct || info->rb_ct || info->rr_ct)
	{
		while (info->ra_ct--)
			rotate_a(&ptr_a);
		while (info->rb_ct--)
			rotate_b(&ptr_b);
		while (info->rr_ct--)
			rotate_ab(&ptr_a, &ptr_b);
	}
	if (info->rra_ct || info->rrb_ct || info->rrr_ct)
	{
		while (info->rra_ct--)
			reverse_rotate_a(&ptr_a);
		while (info->rrb_ct--)
			reverse_rotate_b(&ptr_b);
		while (info->rrr_ct--)
			reverse_rotate_ab(&ptr_a, &ptr_b);
	}
}

void	insertion(t_info *info)
{
	t_list	*ptr_b;

	ptr_b = info->b->head;
	while (ptr_b)
	{
		find_costs_manager(info);
		do_operations(info);
		reset_costs(info);
	}
}