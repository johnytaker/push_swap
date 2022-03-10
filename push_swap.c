/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/08 00:00:42 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ptr_a;
	t_list	*ptr_b;

	stack_b = NULL;
	check_parameters(argc, argv);
	stack_a = create_lst(argv);
	append_id(&stack_a, argv, argc - 1);

	push_all_b(&stack_a, &stack_b);
	triple_sort_a(&stack_a);
	ptr_a = stack_a;
	ptr_b = stack_b;
	while (ptr_b)
	{
		ptr_b->score = find_score(&stack_a, &stack_b, ptr_b->id);
		ptr_b = ptr_b->next;
	}
	triple_sort_a(&stack_a);
	sort_all(&stack_a, &stack_b);
	// while (stack_a)
	// {
	// 	printf("%d\n", stack_a->data);
	// 	stack_a= stack_a->next;
	// }
	// printf("\n\n");
	// while (stack_b)
	// {
	// 	printf("%d | %d\n", stack_b->data, stack_b->score);
	// 	stack_b= stack_b->next;
	// }
	return (0);
}
