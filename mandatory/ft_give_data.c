/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:49:14 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/30 11:12:16 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	give_data(int ac, char **av)
{
	t_data	data;
	long	*eating_number;

	eating_number = malloc(sizeof(long));
	data.philos = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		*(eating_number) = ft_atoi(av[5]);
		data.eating_number = eating_number;
	}
	else if (ac == 5)
	{
		*(eating_number) = -1;
		data.eating_number = eating_number;
	}
	return data;
}
