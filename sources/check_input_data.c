/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:06:45 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/31 20:04:43 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_input_sorted(char **data)
{
	int	i;

	i = 0;
	while (data[i + 1])
	{
		if (ft_atoi(data[i]) > ft_atoi(data[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_input_repeat(char **data)
{
	int	i;
	int	j;

	i = 0;
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

void	check_parameters(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	if (i < 2)
		exit(EXIT_FAILURE);
	else if (is_input_repeat(data))
		print_error();
	else if (is_input_sorted(data))
		exit(EXIT_FAILURE);
}
