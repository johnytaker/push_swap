/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:29 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/21 23:47:14 by iugolin          ###   ########.fr       */
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

	ra = rotate_a_cost(info->a, b_id);
	rb = rotate_b_cost(info->b, b_id);
	rra = reverse_rotate_a_cost(info->a, b_id);
	rrb = reverse_rotate_b_cost(info->b, b_id);
	// printf ("ra -  %d | rb -  %d\n", info->ra_ct, info->rb_ct);
	// printf ("rra -  %d | rrb -  %d\n", info->rra_ct, info->rrb_ct);
	if (ra + rb <= rra + rrb)
	{
		min_cost = ra + rb;
		rra = 0;
		rrb = 0;
	}
	else
	{
		min_cost = rra + rrb;
		ra = 0;
		rb = 0;
	}
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
	if (ft_strcmp("rb", op_name))
		rotate_b(&info->b->head);
	if (ft_strcmp("rra", op_name))
		reverse_rotate_a(&info->a->head);
	if (ft_strcmp("rrb", op_name))
		reverse_rotate_b(&info->b->head);
	if (ft_strcmp("rr", op_name))
		rotate_ab(&info->a->head, &info->b->head);
	if (ft_strcmp("rrr", op_name))
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

void	insertion(t_info *info)
{
	while (info->b->head)
	{
		find_costs_manager(info);
		do_operations(info);
		push_a(&info->a->head, &info->b->head);
		info->a->len++;
		info->b->len--;
		reset_default_costs(info);
	}
}

void	finish_sort(t_stack *stack_a)
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
