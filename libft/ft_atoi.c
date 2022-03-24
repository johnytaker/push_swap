/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:31:35 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/20 17:24:55 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_isspace(char c)
// {
// 	return (c == 32 || (c >= 9 && c <= 13));
// }

static void	check_digit(char c)
{
	if (!ft_isdigit(c) && c != '\0')
	{
		write(1, "Error!\nThe program works with \
numetric parameters only!\n", 57);
		exit(EXIT_FAILURE);
	}
}

static void	check_maxmin_int(unsigned long number, int sign)
{
	if ((number > 2147483648 && sign == -1)
		|| (number > 2147483647 && sign == 1))
	{
		write(1, "Error!\nThe program works with \
values between MININT and MAXINT only!\n", 70);
		exit(EXIT_FAILURE);
	}
}

int	ft_atoi(const char *str)
{
	unsigned long	number;
	int				sign;

	number = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	check_digit(*str);
	while (ft_isdigit(*str))
	{
		number = number * 10 + *str - '0';
		str++;
		check_digit(*str);
	}
	check_maxmin_int(number, sign);
	return (number * sign);
}
