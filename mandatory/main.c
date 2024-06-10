/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:04:16 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/10 12:38:24 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct philo_info
{
	int number;
}philo_info;


t_data give_data(int ac, char **av)
{
	t_data	data;

	data.philos = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data.eating_number = ft_atoi(av[5]);
	return data;
}

void *is_eating(void *param)
{
	philo_info	 *info;

	info = (philo_info *)param;
	printf("philo number %i is eating \n", info->number);
	return (NULL);
}
void *is_sleeping(void *param)
{
	philo_info	 *info;

	info = (philo_info *)param;
	printf("philo number %i is sleeping \n", info->number);
	return (NULL);
}
void *is_thinking(void *param)
{
	philo_info	 *info;

	info = (philo_info *)param;
	printf("philo number %i is thinking \n", info->number);
	return (NULL);
}

philo_info give_info(int i)
{
	philo_info info;

	info.number = i;
	return (info);
}

// void print_info(void *param)
// {
// 	printf()
// }

void make_philos(int number_ph)
{
	int i;
	pthread_t *arr_thr;
	philo_info info;
	arr_thr = malloc(sizeof(pthread_t)*number_ph);

	i = 0;
	while (i < number_ph)
	{
		info = give_info(i);
		// print_info(&info);
		pthread_create(&arr_thr[i], NULL, is_eating, &info);
		pthread_create(&arr_thr[i], NULL, is_sleeping, &info);
		pthread_create(&arr_thr[i], NULL, is_thinking, &info);
		pthread_join(arr_thr[i], NULL);
		printf("\n");
		i++;
	}
}

void philo(int ac, char **av)
{
	t_data	data;

	data = give_data(ac, av);
	make_philos(data.philos);
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