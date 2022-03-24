/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/24 18:01:05 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_info	*info;

	info = NULL;
	check_parameters(argc, argv);
	info = create_main_struct(argv, argc);
	// print_max_min_mid(info->a);
	// print_one_stack_with_id(info->a);
	if (info)
	{
		if (info->a->len > 3 && info->a->len < 6)
		{
			fifth_sort(info);
			exit(EXIT_SUCCESS);
		}
		if (info->a->len > 3)
			fill_b(info);
		triple_sort_a(info->a);
		// print_one_stack_with_id(info->a, "A");
		// print_one_stack_with_id(info->b, "B");
		insertion(info);
		if (info->a->head->id != info->a->min_id)
			make_stack_great_again(info->a);
		// push_b(&info->a->head, &info->b->head);
		// push_b(&info->a->head, &info->b->head);
		// print_stacks_with_ids(info->a, info->b);
		// do_reverse_rotate(&info->a->head, "rra");
		// do_reverse_rotate(&info->b->head, "rrb");
		// reverse_rotate_ab(&info->a->head, &info->b->head);
	}
	return (0);
}
