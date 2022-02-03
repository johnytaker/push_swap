/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:36:44 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/03 19:24:42 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*create_list(int argc, char **argv)
{
	t_list	*head;
	t_list	*tmp;
	int		i;

	i = 1;
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->data = ft_atoi(argv[i]);
	head->next = NULL;
	tmp = head;
	while (argc > 2)
	{
		i++;
		head->next = (t_list *)malloc(sizeof(t_list));
		head = head->next;
		head->data = ft_atoi(argv[i]);
		head->next = NULL;
		argc--;
	}
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_list	*sa;

	if (!(argc > 2))
	{
		ft_putendl_fd("Wrong number of arguments", 1);
		exit(EXIT_FAILURE);
	}
	else if (!is_input_sorted(argv) || is_input_repeat(argv))
	{
		ft_putendl_fd("The stack is already sorted or duplicated", 1);
		exit(EXIT_FAILURE);
	}
	sa = create_list(argc, argv);
	while (sa)
	{
		printf("%d\n", sa->data);
		sa = sa->next;
	}
	// // printf("repeat - %d\n", is_input_repeat(argv));
	// printf("sorted - %d\n", is_input_sorted(argv));
	return (0);
}
