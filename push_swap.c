/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/28 18:20:52 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	check_parameters(argc, argv);
	stack_a = create_lst(argv);
	append_id(&stack_a, argv, argc - 1);

	push_b_less_then_median(&stack_a, &stack_b);

		while (stack_a)
	{
		printf("%d | %d\n", stack_a->data, stack_a->id);
		stack_a= stack_a->next;
	}
	// push_b(&stack_a, &stack_b);
	return (0);
}
