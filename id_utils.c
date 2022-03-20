/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:34:51 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/19 21:03:41 by iugolin          ###   ########.fr       */
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

void	insertion_sort_arr(int *data, int size)
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
}

int	append_id(t_list **lst, char **data, int size)
{
	int		i;
	int		*arr;
	t_list	*ptr;

	arr = int_arr_create(data);
	if (arr)
	{
		insertion_sort_arr(arr, size);
		ptr = *lst;
		while (ptr)
		{
			i = 0;
			while (arr[i] && arr[i] != ptr->data)
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

// int	find_middle_data(t_list **lst)
// {
// 	t_list	*ptr;
// 	int	median;

// 	ptr = (*lst);
// 	median = 1 + (lstsize(lst) - 1) / 2;
// 	while (ptr->next && (ptr->id != median))
// 		ptr = ptr->next;
// 	return (ptr->data);
// }

