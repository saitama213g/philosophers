/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:04:16 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/26 12:24:20 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	my_printf(t_philo_s	*philo, char *str)
{
	pthread_mutex_lock(philo->printf_mtx);
	printf("%ld %i %s\n", get_current_time(), philo->philo_index , str);
	pthread_mutex_unlock(philo->printf_mtx);
}

void	my_usleep(long	mili)
{
	long	starting_time;

	starting_time = get_current_time();
	// optimize more
	// why usleep is not precise
	while (get_current_time() - starting_time < mili)
		usleep(200);
}

void	eating(t_philo_s	*philo)
{
	pthread_mutex_lock(philo->fork1);
	my_printf(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork2);
	// printf("is dead %i\n", philo->is_dead);
	if (ft_getters_value(philo->is_dead, philo->is_dead_mtx))
	{
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		return ;
	}
	my_printf(philo, "has taken a fork");
	ft_setters_value(philo->last_time_eaten, get_current_time(), philo->last_time_eaten_mtx);
	my_printf(philo, "is eating");
	my_usleep(philo->info.time_to_eat);
	philo->eating_counter++;
	if (philo->eating_counter == philo->info.eating_number)
		ft_setters(philo->philos_finished_eating, *(philo->philos_finished_eating) + 1, philo->finished_mtx);
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}

void thinking(t_philo_s	*philo)
{
	if (ft_getters_value(philo->eating_counter, philo->eating_counter_mtx) == philo->info.eating_number)
		return;
	else if (ft_getters_value(philo->is_dead, philo->is_dead_mtx))
		return;
	my_printf(philo, "is thinking");
}

void sleeping(t_philo_s *philo)
{
	if (ft_getters_value(philo->eating_counter, philo->eating_counter_mtx) == philo->info.eating_number)
		return;
	else if (ft_getters_value(philo->is_dead, philo->is_dead_mtx))
		return;
	my_printf(philo, "is sleeping");
	my_usleep(philo->info.time_to_sleep);
}

void	*eat_sleep_think(void	*params)
{
	t_philo_s	*philo;

	philo = (t_philo_s	*)params;

	philo->eating_counter = 0;
	philo->last_time_eaten = get_current_time();
	if (philo->philo_index % 2 == 0)
	{
		while (philo->eating_counter < philo->info.eating_number || philo->info.eating_number == -1)
		{
			sleeping(philo);
			thinking(philo);
			eating(philo);
		}
	}else 
	{
		while (philo->eating_counter < philo->info.eating_number || philo->info.eating_number == -1)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
	}
	return (NULL);
}

void	check_if_dead(t_philo_s *iti)
{
	if (get_current_time() - ft_getters_value(iti->last_time_eaten, iti->last_time_eaten_mtx) >= iti->info.time_to_die)
	{
		ft_setters_value(iti->is_dead, 1, iti->is_dead_mtx);
		my_printf(iti, "*** is dead ***");
	}
}

void check_death_all(t_philo_s	*philos)
{
	t_philo_s	*iti;
	int			i;

	iti = philos;
	i = 0;
	while (ft_getters(philos->philos_finished_eating, philos->finished_mtx) != philos->info.philos)
	{
		i = 0;
		iti = philos;
		while (i < iti->info.philos)
		{
			if (ft_getters_value(iti->eating_counter, iti->eating_counter_mtx) < iti->info.eating_number || iti->info.eating_number == -1)
				check_if_dead(iti);
			iti++;
			i++;
		}
	}
}

void	start_simulation(t_philo_s *philos)
{
	int			i;
	pthread_t	*threads;
	t_philo_s	*phis;

	i = 0;
	threads = philos->arr_thr;
	phis = philos;
	// printf("%i \n", (philos->info).philos);
	while (i < (philos->info).philos)
	{
		pthread_create(threads, NULL, eat_sleep_think, phis);
		phis++;
		threads++;
		i++;
	}
	check_death_all(philos);
	join_thread(philos);
}

t_philo_s	*make_philos(pthread_t	*arr_thr, pthread_mutex_t	*forks, t_data	info)
{
	long			*philos_finished_eating;
	int				i;
	t_philo_s		*first;
	t_philo_s		*philos;
	pthread_mutex_t	*finished_mtx;
	pthread_mutex_t	*eating_counter_mtx;
	pthread_mutex_t	*is_dead_mtx;
	pthread_mutex_t	*printf_mtx;
	pthread_mutex_t	*last_time_eaten_mtx;

	i = 1;
	first = malloc(sizeof(t_philo_s)*info.philos);
	finished_mtx = malloc(sizeof(pthread_mutex_t));
	is_dead_mtx = malloc(sizeof(pthread_mutex_t));
	last_time_eaten_mtx = malloc(sizeof(pthread_mutex_t));
	eating_counter_mtx = malloc(sizeof(pthread_mutex_t));
	printf_mtx = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(finished_mtx, NULL);
	pthread_mutex_init(last_time_eaten_mtx, NULL);
	pthread_mutex_init(eating_counter_mtx, NULL);
	pthread_mutex_init(printf_mtx, NULL);
	pthread_mutex_init(is_dead_mtx, NULL);
	philos_finished_eating = malloc(sizeof(int));
	*philos_finished_eating = 0;
	philos = first;
	give_forks(philos, forks, info.philos);
	while (i <= info.philos)
	{
		philos->philos_finished_eating = philos_finished_eating;
		philos->philo_index = i;
		philos->info = info;
		philos->finished_mtx = finished_mtx;
		philos->printf_mtx = printf_mtx;
		philos->eating_counter_mtx = eating_counter_mtx;
		philos->arr_thr = arr_thr;
		philos->is_dead = 0;
		philos->is_dead_mtx = is_dead_mtx;
		philos->last_time_eaten_mtx = last_time_eaten_mtx;
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