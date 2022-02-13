/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:59:55 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/13 18:03:21 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_number(t_list **lst)
{
	while ((*lst)->id != 1)
		(*lst) = (*lst)->next;
	return ((*lst)->id);
}

int	find_max_number(t_list **lst)
{
	return (lstsize(lst));
}

int	find_median(t_list **lst)
{
	return ((lstsize(lst) - 1) / 2 + 1);
}

void	push_others_to_b(t_list **lst_a, t_list **lst_b)
{
	while ((*lst_a)->next)
	{
		if (find_min_number(lst_a) != (*lst_a)->id
			&& find_max_number(lst_a) != (*lst_a)->id
			&& find_median(lst_a) != (*lst_a)->id)
			push_b(lst_a, lst_b);
		(*lst_a) = (*lst_a)->next;
	}
}
