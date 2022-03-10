/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:59:28 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/07 18:58:34 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_score_b(t_list **lst_b, int b_id)
{
	t_list	*b;
	int		i;

	b = *lst_b;
	i = 0;
	while (b->id != b_id)
	{
		i++;
		b = b->next;
	}
	return (i);
}

int	find_score_a(t_list **lst_a, int b_id)
{
	t_list	*a;
	int		i;

	i = 0;
	a = *lst_a;
	while (a->id < b_id)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	find_score(t_list **lst_a, t_list **lst_b, int b_id)
{

	return (find_score_b(lst_b, b_id) + find_score_a(lst_a, b_id));
}
