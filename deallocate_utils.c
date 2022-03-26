/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:08:39 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/24 22:27:10 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	deallocate_list_memory(t_info *info)
{
	t_list	*tmp_node;

	tmp_node = info->a->head;
	while (tmp_node)
	{
		tmp_node = info->a->head->next;
		free(info->a->head);
		info->a->head = tmp_node;
	}
	info->a->head = NULL;
}

static void	deallocate_struct_memory(t_info *info)
{
	if (info->a->head == NULL)
	{
		free(info->a);
		info->a = NULL;
	}
	if (info->b->head == NULL)
	{
		free(info->b);
		info->b = NULL;
	}
	free(info);
	info = NULL;
}

void	deallocate_all(t_info *info)
{
	deallocate_list_memory(info);
	deallocate_struct_memory(info);
}
