/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:10:53 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/10 11:20:28 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f'
		|| c == '\n')
		return (1);
	return (0);
}

void	print_err(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

static int	check_o(int number, int tmp, int sign)
{
	if (number < tmp && sign == 1)
	{
		write(2, "over flow", 9);
		return (1);
	}
	else if (number > tmp && sign == -1)
	{
		write(2, "under flow", 10);
		return (1);
	}
	return (0);
}

void	check_sign(int *sign, char **s)
{
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*sign = -1;
		(*s)++;
	}
}

int	ft_atoi(char *s)
{
	int	number;
	int	sign;
	int	tmp;

	number = 0;
	sign = 1;
	while (is_space(*s))
		s++;
	check_sign(&sign, &s);
	if (!ft_isdigit(*s))
		return (1);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		tmp = number;
		number = 10 * number + (sign) * (*s - 48);
		if (check_o(number, tmp, sign))
			return (1);
		s++;
	}
	return (number);
}
