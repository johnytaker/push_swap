/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/23 12:33:28 by iugolin          ###   ########.fr       */
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
	print_max_min_mid(info->a);
	// print_one_stack_with_id(info->a);
	if (info)
	{
		fill_b(info);
		triple_sort_a(info->a);
		// print_one_stack_with_id(info->a, "A");
		// print_one_stack_with_id(info->b, "B");
		insertion(info);
		if (info->a->head->id != info->a->min_id)
			finish_sort(info->a);
		// printf("\n### FINAL STATE\n");
		// print_stacks_with_ids(info->a, info->b);
	}
	return (0);
}
