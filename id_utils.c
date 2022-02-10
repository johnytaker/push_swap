/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:34:51 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/10 18:11:08 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"


int	*int_arr_create(char **data, int number)
{
	int	*arr;
	int i;

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
				data[j]= tmp;
			}
			j++;
		}
		i++;
	}
	return (data);
}
