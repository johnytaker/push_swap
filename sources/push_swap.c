/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/31 21:36:37 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack_great_again(t_info *info)
{
	fill_b(info);
	triple_sort(info->a);
	insertion(info);
	if (info->a->head->id != info->a->min_id)
		roll_the_stack_to_start(info);
}

int	main(int argc, char **argv)
{
	char	**data;

	data = parse_arguments(argc, argv);
	if (!data)
		return (0);
	check_parameters(data);
	run_push_swap(data);
	return (0);
}
	//§ print_stacks_with_ids(info->a, info->b);
