/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/04 16:57:51 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*sa;

	if (!(argc > 2))
	{
		ft_putendl_fd("Wrong number of arguments", 1);
		exit(EXIT_FAILURE);
	}
	else if (!is_input_sorted(argv) || is_input_repeat(argv))
	{
		ft_putendl_fd("The stack is already sorted or duplicated", 1);
		exit(EXIT_FAILURE);
	}
	sa = create_lst(argv);
	while (sa)
	{
		printf("%d\n", sa->data);
		sa = sa->next;
	}
	// // printf("repeat - %d\n", is_input_repeat(argv));
	// printf("sorted - %d\n", is_input_sorted(argv));
	return (0);
}