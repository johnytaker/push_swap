/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:23:24 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/02 22:53:11 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_bonus(t_info *info)
{
	t_list	*tmp_node;

	tmp_node = NULL;
	if (info->b->head)
	{
		if (info->b->head->next)
			tmp_node = info->b->head->next;
		push_front(&info->a->head, info->b->head);
		info->b->head = tmp_node;
		info->b->len--;
		info->a->len++;
		// print_op("pa");
	}
}

void	push_b_bonus(t_info *info)
{
	t_list	*tmp_node;

	tmp_node = NULL;
	if (info->a->head)
	{
		if (info->a->head->next)
			tmp_node = info->a->head->next;
		push_front(&info->b->head, info->a->head);
		info->a->head = tmp_node;
		info->a->len--;
		info->b->len++;
		// print_op("pb");
	}
}
