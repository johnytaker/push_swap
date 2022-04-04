/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:08:39 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/02 23:05:30 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deallocate_list_memory(t_info *info)
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

void	deallocate_struct_memory(t_info *info)
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

void	deallocate_array_memory(char **data)
{
	int		i;

	i = 0;
	while (data[i] != NULL)
		free(data[i++]);
	free(data);
}

void	deallocate_all(t_info *info, char **data)
{
	deallocate_array_memory(data);
	deallocate_list_memory(info);
	deallocate_struct_memory(info);
}
