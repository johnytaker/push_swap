/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:29 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/23 16:41:33 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_nbr(int x, int y)
{
	if (x <= y)
		return (x);
	return (y);
}

int	get_min_cost(int x, int y)
{
	if (x && y)
		return (min_nbr(x, y));
	else if (x)
		return (x);
	return (y);
}

int	get_last_id(t_list *head)
{
	while (head && head->next)
		head = head->next;
	return (head->id);
}

void	calc_costs(t_decisions *ptr, int r, int rr)
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
		rotate_a_cost(info->a, b_id, get_last_id(info->a->head)),
		reverse_rotate_a_cost_orig(info->a, b_id));
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
	// print_found_cost(info);

static void	do_operation(char *op_name, t_info *info)
{
	if (ft_strcmp("ra", op_name))
		do_rotate(&info->a->head, "ra");
	else if (ft_strcmp("rb", op_name))
		do_rotate(&info->b->head, "rb");
	else if (ft_strcmp("rra", op_name))
		do_reverse_rotate(&info->a->head, "rra");
	else if (ft_strcmp("rrb", op_name))
		do_reverse_rotate(&info->b->head, "rrb");
	else if (ft_strcmp("rr", op_name) && !ft_strcmp("rrr", op_name))
		rotate_ab(&info->a->head, &info->b->head);
	else if (ft_strcmp("rrr", op_name))
		reverse_rotate_ab(&info->a->head, &info->b->head);
}

static void	direct_roll(t_info *info)
{
	while (info->ra_ct || info->rb_ct)
	{
		if (info->ra_ct && info->rb_ct)
		{
			do_operation("rr", info);
			info->ra_ct--;
			info->rb_ct--;
		}
		else if (info->ra_ct && !info->rb_ct)
		{
			do_operation("ra", info);
			info->ra_ct--;
		}
		else if (info->rb_ct && !info->ra_ct)
		{
			do_operation("rb", info);
			info->rb_ct--;
		}
	}
}

static void	reverse_roll(t_info *info)
{
	while (info->rra_ct || info->rrb_ct)
	{
		if (info->rra_ct && info->rrb_ct)
		{
			do_operation("rrr", info);
			info->rra_ct--;
			info->rrb_ct--;
		}
		else if (info->rra_ct && !info->rrb_ct)
		{
			do_operation("rra", info);
			info->rra_ct--;
		}
		else if (info->rrb_ct && !info->rra_ct)
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
		direct_roll(info);
		reverse_roll(info);
		push_a(&info->a->head, &info->b->head);
		info->a->len++;
		info->b->len--;
		reset_default_costs(info);
	}
}
	// print_stacks_with_ids(info->a, info->b);

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
			do_rotate(&stack_a->head, "ra");
		else if (i > (size / 2))
			do_reverse_rotate(&stack_a->head, "rra");
	}
}
