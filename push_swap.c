/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/21 20:12:46 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	// t_list	*ptr_a;
	// t_list	*ptr_b;

	info = NULL;
	check_parameters(argc, argv);
	info = create_main_struct(argv, argc);
	if (info)
	{
		fill_b(info);
		// ptr_a = info->a->head;
		// ptr_b = info->b->head;
		triple_sort_a(info->a);
		insertion(info);
		// if (info->a->head->id != info->a->min_id)
		// 	finish_sort(info->a);
		while (info->a->head)
		{
			printf("%d | %d\n", info->a->head->data, info->a->head->id);
			info->a->head = info->a->head->next;
		}
		puts("\n\n");
		while (info->b->head)
		{
			printf("%d | %d\n", info->b->head->data, info->b->head->id);
			info->b->head = info->b->head->next;
		}
	}
	return (0);
}
