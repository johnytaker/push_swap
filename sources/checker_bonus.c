/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:10:22 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/31 22:49:22 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_operation(char **op_name, t_info *checker_st)
{
	if(ft_strcmp("pa\n", *op_name))
		push_a(checker_st);
	else if(ft_strcmp("pb\n", *op_name))
		push_b(checker_st);
	else if (ft_strcmp("sa\n", *op_name))
		do_swap(&checker_st->a->head, "sa");
	else if (ft_strcmp("sb\n", *op_name))
		do_swap(&checker_st->b->head, "sb");
	else if (ft_strcmp("ss\n", *op_name))
		swap_ab(&checker_st->a->head, &checker_st->b->head);
	else if (ft_strcmp("ra\n", *op_name))
		do_rotate(&checker_st->a->head, "ra");
	else if (ft_strcmp("rb\n", *op_name))
		do_rotate(&checker_st->b->head, "rb");
	else if (ft_strcmp("rra\n", *op_name))
		do_reverse_rotate(&checker_st->a->head, "rra");
	else if (ft_strcmp("rrb\n", *op_name))
		do_reverse_rotate(&checker_st->b->head, "rrb");
	else if (ft_strcmp("rr\n", *op_name) && !ft_strcmp("rrr\n", *op_name))
		rotate_ab(&checker_st->a->head, &checker_st->b->head);
	else if (ft_strcmp("rrr\n", *op_name))
		reverse_rotate_ab(&checker_st->a->head, &checker_st->b->head);
	else
		return (-1);
	return (1);
}

static int	is_list_sorted(t_stack *stack)
{
	t_list	*ptr;

	ptr = stack->head;
	while(ptr->next)
	{
		if (ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

static void	check_sort(t_info *checker_st)
{
	ft_putendl_fd("OK", 1);
	if (is_list_sorted(checker_st->a) && checker_st->b->head == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

static void	read_instructions(t_info *checker_st)
{
	char	*inst;
	int		flag;

	flag = 1;
	while (flag)
	{
		inst = get_next_line(0);
		if (inst == NULL)
			flag = 0;
		else
		{
			if (do_operation(&inst, checker_st) == -1)
			{
				ft_putendl_fd("Error", 1);
				free(inst);
			}
		}
		free(inst);
	}
	check_sort(checker_st);
}

int	main(int argc, char **argv)
{
	t_info	*checker_st;
	char	**data;

	data = parse_arguments(argc, argv);
	if (!data)
		return (0);
	check_parameters(data);
	checker_st = create_main_struct(data);
	if (!checker_st)
		return (0);
	// print_stacks_with_ids(checker_st->a, checker_st->b);
	run_push_swap(data);
	read_instructions(checker_st);
	// check_sort(checker_st);
	deallocate_all(checker_st, data);
	return (0);
}
