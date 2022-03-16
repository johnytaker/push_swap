/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/16 13:14:27 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void find_score_main(t_info ptr)
// {
// 	reset_costs(ptr);

// 	while(node)
// 	{
// 		int cost = find_score(ptr);
// 		if cost < ptr->min_cost
// 			ptr->min_cost = cost;
// 			ptr->pop_ind = node->id;
// 	}
// }

static t_stack	*create_stack_a(char **data)
{
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (a)
		a->head = create_lst(data);
	if (a->head)
		a->len = lstsize(&a->head);
	else
		free(a);
	return (a);
}

static t_stack	*create_stack_b(void)
{
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	if (b)
	{
		b->head = NULL;
		b->len = 0;
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
	info->rr_ct = 0;
	info->rrr_ct = 0;
}

t_info	*create_main_struct(char **data)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info)
	{
		reset_costs(info);
		info->a = create_stack_a(data);
		if (!info->a)
		{
			free(info);
			return (NULL);
		}
		info->b = create_stack_b();
		if (!info->b)
		{
			free(info->a);
			free(info);
			return (NULL);
		}
	}
	return (info);
}
