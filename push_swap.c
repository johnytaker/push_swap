/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/24 20:15:41 by iugolin          ###   ########.fr       */
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
	if (info)
	{
		if (argc <= 6)
			sort_small_numbers(info, argc - 1);
		else
		{
			fill_b(info);
			triple_sort(info->a);
			insertion(info);
			if (info->a->head->id != info->a->min_id)
				make_stack_great_again(info->a);
		}
		// print_stacks_with_ids(info->a, info->b);
	}
	return (0);
}
