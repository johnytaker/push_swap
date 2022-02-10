/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:36:44 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/10 18:08:53 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*create_list(int argc, char **argv)
// {
// 	t_list	*head;
// 	t_list	*tmp_node;
// 	int		i;

// 	i = 1;
// 	head = (t_list *)malloc(sizeof(t_list));
// 	if (!head)
// 		return (NULL);
// 	head->data = ft_atoi(argv[i]);
// 	head->next = NULL;
// 	tmp_node = head;
// 	while (argc > 2)
// 	{
// 		i++;
// 		head->next = (t_list *)malloc(sizeof(t_list));
// 		head = head->next;
// 		head->data = ft_atoi(argv[i]);
// 		head->next = NULL;
// 		argc--;
// 	}
// 	return (tmp_node);
// }

t_list	*create_lst(char **data)
{
	t_list	*head_ptr;
	int		i;

	head_ptr = NULL;
	i = 1;
	while (data[i])
	{
		head_ptr = create_node(ft_atoi(data[i++]));
		push_back(&head_ptr, create_node(ft_atoi(data[i++])));
	}
	return (head_ptr);
}


