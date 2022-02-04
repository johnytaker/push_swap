/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:17:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/04 16:32:20 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*start;
	t_list	*p;

	if (lst && *lst)
	{
		start = *lst;
		while (start)
		{
			p = start->next;
			if (del)
				del(start->data);
			free(start);
			start = p;
		}
		*lst = NULL;
	}
}
