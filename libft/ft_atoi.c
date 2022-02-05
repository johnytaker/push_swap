/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:31:35 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/05 19:53:09 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static void	check_digit(char c)
{
	if (!ft_isdigit(c) && c != '\0')
	{
		write(1, "The program works with digits only!\nTry again.\n", 48);
		exit(EXIT_FAILURE);
	}
}

int	ft_atoi(const char *str)
{
	unsigned long	number;
	int				sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		number = number * 10 + *str - '0';
		str++;
		check_digit(*str);
	}
	if (number > 2147483648 && sign == -1)
		return (0);
	else if (number > 2147483647 && sign == 1)
		return (-1);
	return (number * sign);
}
