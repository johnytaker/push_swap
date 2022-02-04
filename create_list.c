/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:36:44 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/04 17:33:53 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*create_list(int argc, char **argv)
// {
// 	t_list	*head;
// 	t_list	*tmp;
// 	int		i;

// 	i = 1;
// 	head = (t_list *)malloc(sizeof(t_list));
// 	if (!head)
// 		return (NULL);
// 	head->data = ft_atoi(argv[i]);
// 	head->next = NULL;
// 	tmp = head;
// 	while (argc > 2)
// 	{
// 		i++;
// 		head->next = (t_list *)malloc(sizeof(t_list));
// 		head = head->next;
// 		head->data = ft_atoi(argv[i]);
// 		head->next = NULL;
// 		argc--;
// 	}
// 	return (tmp);
// }

t_list	*create_lst(char **data)
{
	t_list	*head_ptr;
	int		i;

	head_ptr = NULL;
	i = 1;
	while (data[i])
	{
		if (!head_ptr)
			head_ptr = ft_lstnew(ft_atoi(data[i++]));
		ft_lstadd_back(&head_ptr, ft_lstnew(ft_atoi(data[i++])));
	}
	return (head_ptr);
}
