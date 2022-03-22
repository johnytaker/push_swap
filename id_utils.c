/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:34:51 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/22 01:52:27 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_arr_create(char **data)
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

int	*insertion_sort_arr(int *data, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j >= 0 && data[j] < data[j - 1])
		{
			temp = data[j];
			data[j] = data[j - 1];
			data[j - 1] = temp;
			j--;
		}
		i++;
	}
	return (data);
}

// int	*bubble_sort_id(int *data, int size)
//  {
//  	int	i;
//  	int	j;
//  	int	tmp;

//  	i = 0;
//  	j = 0;
//  	tmp = 0;
//  	while (i < size)
//  	{
//  		j = i + 1;
//  		while (j < size)
//  		{
//  			if (data[i] > data[j])
//  			{
//  				tmp = data[i];
//  				data[i] = data[j];
//  				data[j]= tmp;
//  			}
//  			j++;
//  		}
//  		i++;
//  	}
//  	return (data);
//  }

int	append_id(t_stack *stack_a, char **data, int size)
{
	int		i;
	int		*arr;
	t_list	*ptr;

	arr = int_arr_create(data);
	ptr = stack_a->head;
	if (arr)
	{
		arr = insertion_sort_arr(arr, size);
		while (ptr)
		{
			i = 0;
			while (arr[i] != ptr->data)
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

int	find_max_id(t_list **lst)
{
	return (lstsize(lst));
}

int	find_median_id(t_list **lst)
{
	int		median;

	median = 1 + (lstsize(lst) - 1) / 2;
	return (median);
}

// int	find_min_data(t_list **lst)
// {
// 	t_list	*ptr;
// 	int		min_nb;

// 	ptr = *lst;
// 	min_nb = ptr->data;
// 	while (ptr)
// 	{
// 		if (min_nb < ptr->data)
// 			min_nb = ptr->data;
// 		ptr = ptr->next;
// 	}
// 	return (min_nb);
// }

// int	find_max_data(t_list **lst)
// {
// 	t_list	*ptr;
// 	int		max_nb;

// 	ptr = *lst;
// 	max_nb = ptr->data;
// 	while (ptr)
// 	{
// 		if (max_nb > ptr->data)
// 			max_nb = ptr->data;
// 		ptr = ptr->next;
// 	}
// 	return (max_nb);
// }

// int	find_middle_data(t_info *info)
// {
// 	int	min_data;
// 	int	max_data;
// 	int	median;

// 	min_data = find_min_data(&info->a->head);
// 	max_data = find_max_data(&info->a->head);

// 	median = min_data + (max_data - min_data) / 2;
// 	return (median);
// }

