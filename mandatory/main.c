/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:04:16 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/10 11:22:18 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data give_data(int ac, char **av)
{
	t_data	data;

	data.philos = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	if(ac == 6)
		data.eating_number = ft_atoi(av[5]);
	return data;
}

void philo(int ac, char **av)
{
	t_data	data;

	data = give_data(ac, av);
	// printf("philos %i\n", data.philos);
	// printf("time_to_eat %ld\n", data.time_to_eat);
	// printf("time_to_die %ld\n", data.time_to_die);
	// printf("time_to_sleep %ld\n", data.time_to_sleep);
	// printf("eating_number %i\n", data.eating_number);
}

int main(int ac, char **av)
{
    if (ac == 6 || ac == 5)
    {
		// check_data(ac, av);
		philo(ac, av);
    }else
		write(2, "number of params is not correct\n", 33);
	return (0);
}