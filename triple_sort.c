/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:59:55 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/16 15:20:51 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_id(t_list **lst)
{
	while ((*lst)->id != 1)
		(*lst) = (*lst)->next;
	return ((*lst)->id);
}

int	find_biggest_id(t_list **lst)
{
	return (lstsize(lst));
}

int	find_median_id(t_list **lst)
{
	return (1 + (lstsize(lst) - 1) / 2);
}

// void	push_others_to_b(t_list **lst_a, t_list **lst_b)
// {
// 	int	size;

// 	size = lstsize(lst_a)
// 	while ((*lst_a)->next)
// 	{
// 		if (find_smallest_id(lst_a) != (*lst_a)->id
// 			&& find_biggest_id(lst_a) != (*lst_a)->id
// 			&& find_median_id(lst_a) != (*lst_a)->id)
// 			push_b(lst_a, lst_b);
// 		(*lst_a) = (*lst_a)->next;
// 	}
// }
