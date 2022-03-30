/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:35:56 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/30 21:13:04 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		push_a(info);
		reset_default_costs(info);
	}
}

void	roll_the_stack_to_start(t_info *info)
{
	t_list	*ptr;
	int		i;
	int		size;

	ptr = info->a->head;
	size = info->a->len;
	i = 0;
	while (ptr && ptr->id != info->a->min_id)
	{
		i++;
		ptr = ptr->next;
	}
	ptr = info->a->head;
	while (info->a->head->id != info->a->min_id)
	{
		if (i < (size / 2))
			do_rotate(&info->a->head, "ra");
		else
			do_reverse_rotate(&info->a->head, "rra");
	}
}
