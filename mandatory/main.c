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

void my_printf(t_philo_s	*philo, char *str)
{
	pthread_mutex_lock(philo->printf_mtx);
	printf("philo number %i is %s\n", philo->philo_index , str);
	pthread_mutex_unlock(philo->printf_mtx);
}

void	*eat_sleep_think(void	*params)
{
	t_philo_s	*philo;

	philo = (t_philo_s	*)params;
	while (ft_getters(philo->all_are_created, philo->x_mutex) == 0)
	;

	my_printf(philo, "sleeping");
}

void	start_simulation(t_philo_s *philos)
{
	int			i;
	pthread_t	*threads;
	t_philo_s	*phis;

	i = 0;
	threads = philos->arr_thr;
	phis = philos;
	while (i < philos->info.philos)
	{
		pthread_create(threads, NULL, eat_sleep_think, phis);
		phis++;
		threads++;
		i++;
	}
	ft_setters(philos->all_are_created, 1, philos->x_mutex);
	join_thread(philos);
}

t_philo_s	*make_philos(pthread_t	*arr_thr, pthread_mutex_t	*forks, t_data	info)
{
	int				*all_are_created;
	int				i;
	t_philo_s		*first;
	t_philo_s		*philos;
	pthread_mutex_t	*get_x_mutex;
	pthread_mutex_t	*printf_mtx;

	i = 0;
	first = malloc(sizeof(t_philo_s)*info.philos);
	get_x_mutex = malloc(sizeof(pthread_mutex_t));
	printf_mtx = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(get_x_mutex, NULL);
	pthread_mutex_init(printf_mtx, NULL);
	all_are_created = malloc(sizeof(int));
	*all_are_created = 0;
	philos = first;
	give_forks(philos, forks, info.philos);
	while (i < info.philos)
	{
		philos->all_are_created = all_are_created;
		philos->philo_index = i;
		philos->info = info;
		philos->x_mutex = get_x_mutex;
		philos->printf_mtx = printf_mtx;
		philos->arr_thr = arr_thr;
		philos++;
		i++;
	}
	return (first);
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
	start_simulation(philos);
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