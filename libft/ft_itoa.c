/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:54:42 by aet-tale          #+#    #+#             */
/*   Updated: 2023/12/20 22:40:44 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	give_size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i); 
}

static void	n_check(int *n, int *size, char *number)
{
	if (*n == -2147483648)
	{
		*n = 214748364;
		number[--(*size)] = '8';
	}
	if (*n < 0)
		*n *= -1;
}

char	*ft_itoa(int n)
{
	int		size;
	char	*number;
	int		sign;

	sign = 0;
	size = give_size(n);
	number = malloc(sizeof(char) * (size + 1));
	if (!number)
		return (NULL);
	if (n < 0)
		sign = 1;
	number[size] = '\0';
	n_check(&n, &size, number);
	while (size-- > 0)
	{
		number[size] = n % 10 + 48;
		n /= 10;
	}
	if (sign)
		number[0] = '-';
	return (number);
}
