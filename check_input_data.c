/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:06:45 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/03 19:17:45 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_input_sorted(char **argv)
{
	int	i;

	i = 1;
	while (argv[i + 1])
	{
		if (!(ft_atoi(argv[i]) <= ft_atoi(argv[i + 1])))
			return (1);
		i++;
	}
	return (0);
}

int	is_input_repeat(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j++]))
				return (1);
		}
		i++;
	}
	return (0);
}
