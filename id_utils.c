/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:34:51 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/16 13:44:26 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_arr_create(char **data, int number)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * number);
	while (data[i])
		arr[i] = ft_atoi(data[i++]);
	return (arr);
}

int	*bubble_sort_id(int *data, int size)
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

t_list	*append_id(t_list **lst, char **data, int size)
{
	int		i;
	int		*arr;
	t_list	*ptr;

	i = 0;
	arr = bubble_sort_id(int_arr_create(data, size), size);
	ptr = *lst;
	while (ptr->next)
	{
		i = 0;
		while (arr[i] && arr[i] != ptr->data)
			i++;
		if (arr[i] == ptr->data)
			ptr->id = i + 1;
		ptr = ptr->next;
	}
	return (*lst);
}
