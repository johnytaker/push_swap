/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:34:51 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/23 22:54:07 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*int_arr_create(char **data)
{
	int	*arr;
	int	i;

	i = 1;
	while (data[i])
		i++;
	arr = (int *)malloc(sizeof(int) * i);
	if (arr)
	{
		i = 0;
		while (data[i + 1])
		{
			arr[i] = ft_atoi(data[i + 1]);
			i++;
		}
	}
	return (arr);
}

// static int	*insertion_sort_arr(int *data, int size)
// {
// 	int	i;
// 	int	j;
// 	int	temp;

// 	i = 1;
// 	while (i < size)
// 	{
// 		j = i;
// 		while (j >= 0 && data[j] < data[j - 1])
// 		{
// 			temp = data[j];
// 			data[j] = data[j - 1];
// 			data[j - 1] = temp;
// 			j--;
// 		}
// 		i++;
// 	}
// 	return (data);
// }

static int	*bubble_sort_id(int *data, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (data[i] > data[j])
			{
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (data);
}

int	append_id(t_stack *stack_a, char **data, int size)
{
	int		i;
	int		*arr;
	t_list	*ptr;

	arr = int_arr_create(data);
	ptr = stack_a->head;
	if (arr)
	{
		// arr = insertion_sort_arr(arr, size);
		arr = bubble_sort_id(arr, size);
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

// int	find_max_id(t_list **lst)
// {
// 	return (lstsize(lst));
// }
