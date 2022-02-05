/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/05 21:20:28 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
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
	stack_a = create_lst(argv);
	rotate_a(&stack_a);

	// swap_a(&stack_a);
	while (stack_a)
	{
		printf("%d\n", stack_a->data);
		stack_a = stack_a->next;
	}
	// push_b(&stack_a, &stack_b);
	// printf("%d\n", stack_b->data);
	// printf("%d\n", stack_a->data);
	// write(1, "---------------------\n", 23);
	// push_a(&stack_a, &stack_b);
	// printf("%d\n", stack_b->data);
	// printf("%d\n", stack_a->data);
	// printf("repeat - %d\n", is_input_repeat(argv));
	// printf("sorted - %d\n", is_input_sorted(argv));
	return (0);
}