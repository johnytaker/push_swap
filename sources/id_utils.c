/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:34:51 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/27 16:07:55 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*int_arr_create(char **data, t_stack *stack)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * stack->len);
	if (arr)
	{
		i = 0;
		while (data[i])
		{
			arr[i] = ft_atoi(data[i]);
			i++;
		}
	}
	return (arr);
}

static int	*insertion_sort_arr(int *data, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	temp = 0;
	while (i < size)
	{
		temp = data[i];
		j = i - 1;
		while (j >= 0 && data[j] > temp)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = temp;
		i++;
	}
	return (data);
}

int	append_id(t_stack *stack_a, char **data)
{
	t_list	*ptr;
	int		*arr;
	int		i;

	arr = int_arr_create(data, stack_a);
	ptr = stack_a->head;
	if (arr)
	{
		arr = insertion_sort_arr(arr, stack_a->len);
		while (ptr)
		{
			i = 0;
			while (arr[i] != ptr->value)
				i++;
			ptr->id = i + 1;
			ptr = ptr->next;
		}
		free(arr);
		return (1);
	}
	else
		return (0);
}

int	find_min_id(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr && ptr->id != 1)
		ptr = ptr->next;
	return (ptr->id);
}

int	find_median_id(t_list **lst)
{
	return (1 + (lstsize(lst) - 1) / 2);
}
