/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/14 19:38:12 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info		*info;

	info = NULL;
	check_parameters(argc, argv);
	info = create_main_struct(argv);
	if (!info)
		return (NULL);
	append_id(&info->a->head, argv, argc - 1);

	push_all_b(&info->a->head, &info->b->head);
	triple_sort_a(&info->a->head);
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
