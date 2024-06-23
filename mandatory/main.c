/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:04:16 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/23 20:48:03 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo_s	*make_philos(pthread_t	*arr_thr, pthread_mutex_t	*forks, t_data	info)
{
	int			i;
	t_philo_s	*first;
	t_philo_s	*philos;

	i = 0;
	first = malloc(sizeof(t_philo_s)*info.philos);
	philos = first;
	give_forks(philos, forks, info.philos);
	while (i < info.philos)
	{
		philos->philo_index = i;
		philos->info = info;
		philos->arr_thr = arr_thr;
		philos++;
		i++;
	}
	return (first);
}

void	join_thread(t_philo_s	*philos)
{
	int			i;
	pthread_t	*threads;

	i = 0;
	threads = philos->arr_thr;
	while (i < philos->info.philos)
	{
		pthread_join(*(threads), NULL);
		threads++;
		i++;
	}
}

void	*eat_sleep_think(void	*params)
{
	t_philo_s	*philos;

	philos = (t_philo_s	*)params;
	
}

void	start_simulation(t_philo_s *philos)
{
	int			i;
	pthread_t	*threads;

	i = 0;
	threads = philos->arr_thr;
	while (i < philos->info.philos)
	{
		pthread_create(threads, NULL, eat_sleep_think, philos);
		threads++;
		i++;
	}
	join_thread(philos);
}

void philo(int ac, char **av)
{ 
	pthread_t		*arr_thr;
	pthread_mutex_t	*forks;
	t_philo_s		*philos;
	t_data			info;

	int i = 0;
	info = give_data(ac, av);
	arr_thr = malloc(sizeof(pthread_t)*info.philos);
	forks = malloc(sizeof(pthread_mutex_t)*info.philos);
	while (i < info.philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	philos = make_philos(arr_thr, forks, info);
	// start_simulation(philos);
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