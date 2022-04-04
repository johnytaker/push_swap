/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_and_fill_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:36:44 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/02 23:43:49 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_lst(char **data)
{
	t_list	*head_ptr;
	int		i;

	i = 0;
	head_ptr = NULL;
	head_ptr = create_node(ft_atoi(data[i++]));
	while (data[i])
		push_back(&head_ptr, create_node(ft_atoi(data[i++])));
	return (head_ptr);
}

void	fill_b(t_info *info)
{
	int	size;

	size = info->a->len;
	while (size--)
	{
		if (info->a->min_id == info->a->head->id
			|| info->a->median_id == info->a->head->id
			|| info->a->max_id == info->a->head->id)
			do_rotate(&info->a->head, "ra");
		else if (info->a->median_id > info->a->head->id)
		{
			push_b(info);
			do_rotate(&info->b->head, "rb");
		}
		else
			push_b(info);
	}
}
