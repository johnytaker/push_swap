/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:06:45 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/04 17:32:43 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_input_sorted(char **data)
{
	int	i;

	i = 1;
	while (data[i + 1])
	{
		if (!(ft_atoi(data[i]) <= ft_atoi(data[i + 1])))
			return (1);
		i++;
	}
	return (0);
}

int	is_input_repeat(char **data)
{
	int	i;
	int	j;

	i = 1;
	while (data[i])
	{
		j = i + 1;
		while (data[j])
		{
			if (ft_atoi(data[i]) == ft_atoi(data[j++]))
				return (1);
		}
		i++;
	}
	return (0);
}
