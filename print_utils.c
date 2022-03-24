/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:07:01 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/23 12:07:50 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char *op)
{
	ft_putendl_fd(op, 1);
}

void	print_max_min_mid(t_stack *stack)
{
	printf("max = %d, mid = %d, min = %d\n", stack->max_id, stack->median_id, stack->min_id);
}

void	print_one_stack_with_id(t_stack *stack, char *name)
{
	t_list	*tmp;

	tmp = stack->head;
	printf("\n%s\n", name);
	while (tmp)
	{
		printf("%d | %d\n", tmp->value, tmp->id);
		tmp = tmp->next;
	}
}

void	print_found_cost(t_info *info)
{
	printf("\nFound cost\n");
	printf("min cost %d pop_id %d\nra %d rra %d\nrb %d rrb %d\n\n", info->min_cost, info->pop_ind, info->ra_ct, info->rra_ct, info->rb_ct, info->rrb_ct);
}

void print_stacks_with_ids(t_stack *a, t_stack *b)
{
	t_list *tmp_a = a->head;
	t_list *tmp_b = b->head;
	char *a_elem, *a_id, *b_elem, *b_id;

	printf("\n%s\t\t|\t%5s\n", "A", "B");
	while (tmp_a || tmp_b)
	{
		a_elem = tmp_a ? ft_itoa(tmp_a->value) : "_";
		a_id = tmp_a ? ft_itoa(tmp_a->id) : "_";
		b_elem = tmp_b ? ft_itoa(tmp_b->value) : "_";
		b_id = tmp_b ? ft_itoa(tmp_b->id) : "_";
		printf("%-s(%s)\t|\t%s(%s)\n", a_elem, a_id, b_elem, b_id);
		tmp_a = tmp_a ? tmp_a->next : NULL;
		tmp_b = tmp_b ? tmp_b->next : NULL;
	}
	printf("\n");
}

// void print_sorted(t_stack *stack)
// {
// 	double *arr = malloc(sizeof(stack->len));
// 	double *sorted;

// 	t_list *tmp = stack->head;
// 	int i = 0;
// 	while (tmp)
// 	{
// 		arr[i] = tmp->data;
// 		i++;
// 		tmp = tmp->next;
// 	}

// 	sorted = qsort(arr)

// }
