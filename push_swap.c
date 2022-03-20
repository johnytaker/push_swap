/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/20 13:57:28 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	// int		*arr;
	// int		i;

	info = NULL;
	check_parameters(argc, argv);
	info = create_main_struct(argv, argc);
	if (info)
	{
		// append_id(&info->a->head, argv, argc - 1);
		fill_b(info);
		triple_sort_a(&info->a->head);
		insertion(info);
		// if (info->a->head->data != info->a->min)
		// finish_sort(info->a);
		while (info->a->head)
		{
			printf("%d | %d\n", info->a->head->data, info->a->head->id);
			info->a->head = info->a->head->next;
		}
		puts("\n\n");
		while (info->b->head)
		{
			printf("%d | %d\n", info->a->head->data, info->a->head->id);
			info->b->head = info->b->head->next;
		}
		// arr = int_arr_create(argv);
		// insertion_sort_arr(arr, argc - 1);
		// i = 0;
		// while (arr[i])
		// {
		// 	printf("%d | %d\n", arr[i], i);
		// 	i++;
		// }
	}
	return (0);
}
