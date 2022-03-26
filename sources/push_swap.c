/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/26 22:58:10 by iugolin          ###   ########.fr       */
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

static char	**parse_arguments(int argc, char **argv)
{
	char	*arg_str;
	char	**argv_new;
	char	*tmp;
	int		i;
	int		size;

	size = argc - 1;
	arg_str = ft_strdup("");
	if (!arg_str)
		return (NULL);
	i = 1;
	while (size--)
	{
		tmp = arg_str;
		arg_str = ft_strjoin(arg_str, argv[i++]);
		free(tmp);
		if (!arg_str)
			return (NULL);
	}
	argv_new = ft_split(arg_str, ' ');
	if (arg_str)
		free(arg_str);
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
	if (info)
	{
		if (info->a->len < 6)
			sort_small_numbers(info);
		else
			make_stack_great_again(info);
		// print_stacks_with_ids(info->a, info->b);
		deallocate_all(info, data);
	}
	return (0);
}
