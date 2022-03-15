/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:34:51 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/12 19:38:07 by iugolin          ###   ########.fr       */
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
	if (!arr)
		return (NULL);
	i = 0;
	while (data[i + 1])
	{
		arr[i] = ft_atoi(data[i + 1]);
		i++;
	}
	return (arr);
}

void	quick_sort(int *data, int size)
{
	int	i;
	int	j;
	int	mid;
	int	tmp;

	i = 0;
	j = size - 1;
	mid = data[size / 2];
	do
	{
		while (data[i] < mid)
			i++;
		while (data[j] > mid)
			j--;
		if (i <= j)
		{
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		quick_sort(data, j + 1);
	if (i < size)
		quick_sort(&data[i], size - i);
}

void	append_id(t_list **lst, char **data, int size)
{
	int		i;
	int		*arr;
	t_list	*ptr;

	arr = int_arr_create(data);
	quick_sort(arr, size);
	ptr = *lst;
	while (ptr)
	{
		i = 0;
		while (arr[i] && arr[i] != ptr->data)
			i++;
		if (arr[i] == ptr->data)
			ptr->id = i + 1;
		ptr = ptr->next;
	}
	free(arr);
}
