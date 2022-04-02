/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:17:59 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/02 00:38:58 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_arguments(int argc, char **argv)
{
	char	**argv_new;
	char	*arg_str;
	char	*space_delim;
	int		size;
	int		i;

	size = argc - 1;
	i = 1;
	space_delim = ft_strdup(" ");
	while (size--)
	{
		arg_str = ft_strjoin_free(arg_str, argv[i++]);
		arg_str = ft_strjoin_free(arg_str, space_delim);
		if (!arg_str)
			return (NULL);
	}
	argv_new = ft_split(arg_str, ' ');
	free(space_delim);
	free(arg_str);
	return (argv_new);
}

void	run_push_swap(char **data)
{
	t_info	*info;

	info = create_main_struct(data);
	if (!info)
		return ;
	if (info->a->len < 6)
		sort_small_numbers(info);
	else
		make_stack_great_again(info);
	// print_sacks_with_ids(info->a, info->b);
	// deallocate_all(info, data);
}
