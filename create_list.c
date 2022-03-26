/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:36:44 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/26 14:50:09 by iugolin          ###   ########.fr       */
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
