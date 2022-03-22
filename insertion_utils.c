/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:29 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/22 15:25:04 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_costs(t_info *info, int b_id)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	min_cost;

	ra = rotate_cost(info->a, b_id + 1);
	rb = rotate_cost(info->b, b_id);
	rra = reverse_rotate_cost(info->a, b_id + 1);
	rrb = reverse_rotate_cost(info->b, b_id);
	// printf ("ra -  %d | rb -  %d\n", info->ra_ct, info->rb_ct);
	// printf ("rra -  %d | rrb -  %d\n", info->rra_ct, info->rrb_ct);
	// if (ra + rb <= rra + rrb)
	// {
	// 	min_cost = ra + rb;
	// 	rra = 0;
	// 	rrb = 0;
	// }
	// else
	// {
	// 	min_cost = rra + rrb;
	// 	ra = 0;
	// 	rb = 0;
	// }
	int	smallest_a;
	if (ra && rra)
	{
		if (ra <= rra)
			smallest_a = ra;
		else
			smallest_a = rra;
	}
	else
	{
		if (ra)
			smallest_a = ra;
		else
			smallest_a = rra;
	}
	if (smallest_a == ra)
		ra = ra;
	else
		ra = 0;
	if (smallest_a == rra)
		rra = rra;
	else
		rra = 0;
	int	smallest_b;
	if (rb && rrb)
	{
		if (rb <= rrb)
			smallest_b = rb;
		else
			smallest_b = rrb;
	}
	else
	{
		if (rb)
			smallest_b = rb;
		else
			smallest_b = rrb;
	}
	if (smallest_b == rb)
		rb = rb;
	else
		rb = 0;
	if (smallest_b == rrb)
		rrb = rrb;
	else
		rrb = 0;
	min_cost = smallest_a + smallest_b;
	if (info->min_cost == DEFAULT_COST
		|| info->min_cost > min_cost)
	{
		reset_costs(info);
		info->min_cost = min_cost;
		info->pop_ind = b_id;
		info->ra_ct = ra;
		info->rb_ct = rb;
		info->rra_ct = rra;
		info->rrb_ct = rrb;
		// printf ("ra_ct -  %d | rb_ct -  %d\n", info->ra_ct, info->rb_ct);
		// printf ("rra_ct -  %d | rrb_ct -  %d\n", info->rra_ct, info->rrb_ct);
	}
	else if (info->min_cost <= min_cost)
		return ;

}

static void	find_costs_manager(t_info *info)
{
	t_list	*ptr;

	ptr = info->b->head;
	while (ptr)
	{
		find_costs(info, ptr->id);
		ptr = ptr->next;
	}
}

static void	do_operation(char *op_name, t_info *info)
{
	if (ft_strcmp("ra", op_name))
		rotate_a(&info->a->head);
	else if (ft_strcmp("rb", op_name))
		rotate_b(&info->b->head);
	else if (ft_strcmp("rra", op_name))
		reverse_rotate_a(&info->a->head);
	else if (ft_strcmp("rrb", op_name))
		reverse_rotate_b(&info->b->head);
	else if (ft_strcmp("rr", op_name))
		rotate_ab(&info->a->head, &info->b->head);
	else if (ft_strcmp("rrr", op_name))
		reverse_rotate_ab(&info->a->head, &info->b->head);
}

static void	do_operations(t_info *info)
{
	while (info->ra_ct && info->rb_ct)
	{
		do_operation("rr", info);
		info->ra_ct--;
		info->rb_ct--;
	}
	while (info->ra_ct || info->rb_ct)
	{
		if (info->ra_ct)
		{
			do_operation("ra", info);
			info->ra_ct--;
		}
		if (info->rb_ct)
		{
			do_operation("rb", info);
			info->rb_ct--;
		}
	}
	while (info->rra_ct && info->rrb_ct)
	{
		do_operation("rrr", info);
		info->rra_ct--;
		info->rrb_ct--;
	}
	while (info->rra_ct || info->rrb_ct)
	{
		if (info->rra_ct)
		{
			do_operation("rra", info);
			info->rra_ct--;
		}
		if (info->rrb_ct)
		{
			do_operation("rrb", info);
			info->rrb_ct--;
		}
	}
}

static void	roll_to_sorted_position(t_stack *stack_a)
{
	t_list	*ptr;
	int		i;
	int		size;

	ptr = stack_a->head;
	size = stack_a->len;
	i = 0;
	while (ptr && ptr->id != stack_a->min_id)
	{
		i++;
		ptr = ptr->next;
	}
	ptr = stack_a->head;
	while (stack_a->head->id != stack_a->min_id)
	{
		if (i < (size / 2))
			rotate_a(&stack_a->head);
		else if (i > (size / 2))
			reverse_rotate_a(&stack_a->head);
	}
}

void	insertion(t_info *info)
{
	while (info->b->len != 0)
	{
		find_costs_manager(info);
		do_operations(info);
		push_a(&info->a->head, &info->b->head);
		info->a->len++;
		info->b->len--;
		reset_default_costs(info);
	}
	if (info->a->head->id != info->a->min_id)
		roll_to_sorted_position(info->a);
}

