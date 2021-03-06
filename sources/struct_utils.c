/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/26 14:52:09 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_stack_a(char **data)
{
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (a)
		a->head = create_lst(data);
	if (a->head)
	{
		a->len = lstsize(&a->head);
		if (!append_id(a, data))
		{
			free(a);
			return (NULL);
		}
		a->min_id = find_min_id(&a->head);
		a->median_id = find_median_id(&a->head);
		a->max_id = a->len;
	}
	else
		free(a);
	return (a);
}

static t_stack	*create_stack_b(t_stack *stack_a)
{
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	if (b)
	{
		b->head = NULL;
		b->len = 0;
		b->min_id = stack_a->min_id;
		b->median_id = stack_a->median_id;
		b->max_id = stack_a->max_id;
	}
	return (b);
}

void	reset_costs(t_info *info)
{
	info->min_cost = 0;
	info->pop_ind = 0;
	info->ra_ct = 0;
	info->rb_ct = 0;
	info->rra_ct = 0;
	info->rrb_ct = 0;
}

void	reset_default_costs(t_info *info)
{
	info->min_cost = DEFAULT_COST;
	info->pop_ind = 0;
	info->ra_ct = 0;
	info->rb_ct = 0;
	info->rra_ct = 0;
	info->rrb_ct = 0;
}

t_info	*create_main_struct(char **data)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info)
	{
		reset_default_costs(info);
		info->a = create_stack_a(data);
		if (!info->a)
		{
			free(info);
			return (NULL);
		}
		info->b = create_stack_b(info->a);
		if (!info->b)
		{
			free(info->a);
			free(info);
			return (NULL);
		}
	}
	return (info);
}
