/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/20 13:22:40 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_stack_a(char **data, int size)
{
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (a)
		a->head = create_lst(data);
	if (a->head)
	{
		if (!append_id(&a->head, data, size - 1))
		{
			free(a);
			return (NULL);
		}
		a->len = lstsize(&a->head);
		a->min_id = find_min_id(&a->head);
		a->median_id = find_median_id(&a->head);
		a->max_id = find_max_id(&a->head);
		// a->min_id = find_min_data(&a->head);
		// a->median_id = find_middle_data(&a->head);
		// a->max_id = find_max_data(&a->head);
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
		b->min_id = stack_a->min_id;;
		b->median_id = stack_a->median_id;
		b->max_id = stack_a->max_id;;
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

t_info	*create_main_struct(char **data, int size)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info)
	{
		reset_default_costs(info);
		info->a = create_stack_a(data, size);
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
