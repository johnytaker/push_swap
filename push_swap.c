/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/09 14:44:31 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	// int		tmp;

	stack_b = NULL;
	check_parameters(argc, argv);
	stack_a = create_lst(argv);
	reverse_rotate_a(&stack_a);

	// swap_a(&stack_a);
	while (stack_a)
	{
		printf("%d\n", stack_a->data);
		stack_a = stack_a->next;
	}
	// push_b(&stack_a, &stack_b);
	return (0);
}
