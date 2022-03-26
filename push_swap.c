/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/26 14:56:05 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

void	make_stack_great_again(t_info *info)
{
	fill_b(info);
	triple_sort(info->a);
	insertion(info);
	if (info->a->head->id != info->a->min_id)
		roll_the_stack_to_start(info);
}

static char	**parse_arguments(int argc, char **argv)
{
	char	*arg_str;
	char	**argv_new;
	int		i;
	int		size;

	size = argc - 1;
	i = 1;
	arg_str = ft_strdup("");
	if (!arg_str)
		return (NULL);
	while (size--)
	{
		arg_str = ft_strjoin(arg_str, argv[i]);
		if (!arg_str)
			return (NULL);
		i++;
	}
	argv_new = ft_split(arg_str, ' ');
	if (!argv_new)
		return (NULL);
	return (argv_new);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	char	**data;

	info = NULL;
	data = parse_arguments(argc, argv);
	check_parameters(data);
	info = create_main_struct(data);
	print_stacks_with_ids(info->a, info->b);
	if (info)
	{
		if (info->a->len < 6)
			sort_small_numbers(info);
		else
			make_stack_great_again(info);
		print_stacks_with_ids(info->a, info->b);
		deallocate_all(info);
	}
	return (0);
}
