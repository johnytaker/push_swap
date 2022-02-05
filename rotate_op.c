/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:05:11 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/05 21:22:53 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **lst_a)
{
	t_list	*tmp_node;

	if (*lst_a && ((*lst_a)->next))
	{
		tmp_node = (*lst_a)->next;
		push_back(lst_a, *lst_a);
		*lst_a = tmp_node;
	}
}
