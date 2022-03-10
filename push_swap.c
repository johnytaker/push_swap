/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/10 20:59:07 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// t_list	*stack_a;
	// t_list	*stack_b;
	t_info		*info;

	info = NULL;
	check_parameters(argc, argv);
	allocate_stacks_struct(info);
	info = (t_info *)malloc(sizeof(t_info));
	info->a->head = create_lst(argv);
	info->b->head = NULL;
	// stack_a = create_lst(argv);
	append_id(&info->a->head, argv, argc - 1);

	push_all_b(&info->a->head, &info->b->head);
	triple_sort_a(&info->a->head);
	// while (ptr_b)
	// {
	// 	ptr_b->score = find_score(&stack_a, &stack_b, ptr_b->id);
	// 	ptr_b = ptr_b->next;
	// }
	sort_all(&info->a->head, &info->b->head);
	while (info->a->head)
	{
		printf("%d\n", info->a->head->data);
		info->a->head = info->a->head->next;
	}
	// printf("\n\n");
	// while (stack_b)
	// {
	// 	printf("%d | %d\n", stack_b->data, stack_b->score);
	// 	stack_b= stack_b->next;
	// }
	return (0);
}
