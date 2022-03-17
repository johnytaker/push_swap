/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/17 20:09:19 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_list	*ptr_a;
	t_list	*ptr_b;

	info = NULL;
	ptr_a = NULL;
	ptr_b = NULL;
	check_parameters(argc, argv);
	info = create_main_struct(argv);
	// if (info)
	// {
	// ptr_a = info->a->head;
	// ptr_b = info->b->head;
	append_id(&info->a->head, argv, argc - 1);
	push_all_b(&info->a->head, &info->b->head);
	triple_sort_a(&info->a->head);
		// sort_all(&info->a->head, &info->b->head);
	insertion(info);
	// while (ptr_a)
	// {
	// 	printf("%d\n", ptr_a->data);
	// 	ptr_a = ptr_a->next;
	// }
	// puts("\n\n");
	// while (ptr_b)
	// {
	// 	printf("%d\n", ptr_b->data);
	// 	ptr_b = ptr_b->next;
	// }
		// while (info->b->head)
		// {
		// 	printf("%d\n", info->b->head->data);
		// 	info->b->head= info->b->head->next;
		// }


	while (info->a->head)
	{
		printf("%d\n", info->a->head->data);
		info->a->head = info->a->head->next;
	}

	printf("\n\n");
	while (info->b->head)
	{
		printf("%d\n", info->b->head->data);
		info->b->head= info->b->head->next;
	}
	// }
	return (0);
}
