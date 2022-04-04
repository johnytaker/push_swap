/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:10:22 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/04 14:47:59 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_operation(char *op_name, t_info *checker_st)
{
	if (ft_strcmp(op_name, "pa\n"))
		push_a_bonus(checker_st);
	else if (ft_strcmp(op_name, "pb\n"))
		push_b_bonus(checker_st);
	else if (ft_strcmp(op_name, "sa\n"))
		do_swap_bonus(&checker_st->a->head);
	else if (ft_strcmp(op_name, "sb\n"))
		do_swap_bonus(&checker_st->b->head);
	else if (ft_strcmp(op_name, "ss\n"))
		swap_ab_bonus(&checker_st->a->head, &checker_st->b->head);
	else if (ft_strcmp(op_name, "ra\n"))
		do_rotate_bonus(&checker_st->a->head);
	else if (ft_strcmp(op_name, "rb\n"))
		do_rotate_bonus(&checker_st->b->head);
	else if (ft_strcmp(op_name, "rra\n"))
		do_reverse_rotate_bonus(&checker_st->a->head);
	else if (ft_strcmp(op_name, "rrb\n"))
		do_reverse_rotate_bonus(&checker_st->b->head);
	else if (ft_strcmp(op_name, "rr\n"))
		rotate_ab_bonus(&checker_st->a->head, &checker_st->b->head);
	else if (ft_strcmp(op_name, "rrr\n"))
		reverse_rotate_ab_bonus(&checker_st->a->head, &checker_st->b->head);
	else
		return (-1);
	return (1);
}

static int	is_list_sorted(t_stack *stack)
{
	t_list	*ptr;

	ptr = stack->head;
	while (ptr->next)
	{
		if (ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

static void	check_sort(t_info *checker_st)
{
	if (is_list_sorted(checker_st->a) && !checker_st->b->head)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

static void	stdin_handler(t_info *checker_st)
{
	char	*inst;
	int		flag;

	flag = 1;
	while (flag)
	{
		inst = get_next_line(0);
		if (inst == NULL)
			flag = 0;
		else if (do_operation(inst, checker_st) == -1)
			print_error();
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
	stdin_handler(checker_st);
	deallocate_all(checker_st, data);
	return (0);
}
