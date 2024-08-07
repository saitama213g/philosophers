/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:04:16 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/05 11:10:25 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	my_printf(t_philo_s	*philo, char *str)
{
	pthread_mutex_lock(&philo->info.printf_mtx);
	if (ft_getters(philo->stop_simulation, &philo->info.stop_simulation_mtx))
	{
		pthread_mutex_unlock(&philo->info.printf_mtx);
		return 0;
	}
	printf("%ld %i %s\n", get_current_time() - ft_getters(philo->starting_of_simulation, &philo->info.starting_of_simulation_mtx), philo->philo_index , str);
	// printf("%ld %i %s\n", get_current_time() - ft_getters(philo->starting_of_simulation, &philo->info.starting_of_simulation_mtx), philo->philo_index , str);
	pthread_mutex_unlock(&philo->info.printf_mtx);
	return 1;
}

void	my_usleep(long	mili)
{
	long	starting_time;

	starting_time = get_current_time();
	// optimize more
	// why usleep is not precise
	while (1)
	{
		if (get_current_time() - starting_time >= mili)
			break;
		usleep(100);
	}
}

void	eating(t_philo_s	*philo)
{
	if (ft_getters(philo->stop_simulation, &philo->info.stop_simulation_mtx) || philo->eating_counter == ft_getters(philo->info.eating_number, &philo->info.eating_number_mtx))
		return ;
	pthread_mutex_lock(philo->fork1);
	if (ft_getters(philo->stop_simulation, &philo->info.stop_simulation_mtx) || philo->eating_counter == ft_getters(philo->info.eating_number, &philo->info.eating_number_mtx))
		return ;
	my_printf(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork2);
	if (ft_getters(philo->stop_simulation, &philo->info.stop_simulation_mtx))
	{
		pthread_mutex_unlock(philo->fork2);
		pthread_mutex_unlock(philo->fork1);
		return ;
	}
	my_printf(philo, "has taken a fork");
	
	pthread_mutex_lock(&philo->last_time_eaten_mtx);
	philo->last_time_eaten = get_current_time();
	pthread_mutex_unlock(&philo->last_time_eaten_mtx);

	my_printf(philo, "is eating");
	my_usleep(philo->info.time_to_eat);
	
	pthread_mutex_lock(&philo->eating_counter_mtx);
	philo->eating_counter = philo->eating_counter + 1;
	pthread_mutex_unlock(&philo->eating_counter_mtx);
	
	if (ft_getters_value(philo->eating_counter, &philo->eating_counter_mtx) == ft_getters(philo->info.eating_number, &philo->info.eating_number_mtx))
	{
		pthread_mutex_lock(&philo->info.finished_mtx);
		*(philo->philos_finished_eating) = *(philo->philos_finished_eating) + 1;
		pthread_mutex_unlock(&philo->info.finished_mtx);
	}
		// ft_setters(philo->philos_finished_eating, *(philo->philos_finished_eating) + 1, &philo->info.finished_mtx);

	pthread_mutex_unlock(philo->fork2);
	pthread_mutex_unlock(philo->fork1);
}

void thinking(t_philo_s	*philo)
{
	if (ft_getters_value(philo->eating_counter, &philo->eating_counter_mtx) == ft_getters(philo->info.eating_number, &philo->info.eating_number_mtx))
		return ;
	else if (ft_getters(philo->stop_simulation, &philo->info.stop_simulation_mtx))
		return ;
	my_printf(philo, "is thinking");
}

void	make_one_philo(t_philo_s	*philo)
{
	my_printf(philo, "is thinking");
	my_printf(philo, "has taken a fork");
	my_usleep(philo->info.time_to_die);
	my_printf(philo, "has died");
}

void	sleeping(t_philo_s	*philo)
{
	if (ft_getters_value(philo->eating_counter, &philo->eating_counter_mtx) == ft_getters(philo->info.eating_number, &philo->info.eating_number_mtx))
		return ;
	else if (ft_getters(philo->stop_simulation, &philo->info.stop_simulation_mtx))
		return ;
	my_printf(philo, "is sleeping");
	my_usleep(philo->info.time_to_sleep);
}

void	*eat_sleep_think(void	*params)
{
	t_philo_s	*philo;

	philo = (t_philo_s	*)params;

	philo->eating_counter = 0;
	pthread_mutex_lock(&philo->last_time_eaten_mtx);
	philo->last_time_eaten =  get_current_time();
	pthread_mutex_unlock(&philo->last_time_eaten_mtx);
	if (philo->info.philos == 1)
		make_one_philo(philo);
	else
	{
		if (philo->philo_index % 2 == 0)
			sleeping(philo);
		while (ft_getters(philo->info.eating_number, &philo->info.eating_number_mtx) == -1 || !ft_getters(philo->stop_simulation, &philo->info.stop_simulation_mtx))
		{
			thinking(philo);
			eating(philo);
			if (ft_getters_value(philo->eating_counter, &philo->eating_counter_mtx) == ft_getters(philo->info.eating_number, &philo->info.eating_number_mtx))
				return (NULL);
			sleeping(philo);
		}
	}
	return (NULL); 
}

int	check_if_dead(t_philo_s	*iti)
{
	usleep(100);
	if ((get_current_time() - ft_getters_value(iti->last_time_eaten, &iti->last_time_eaten_mtx)) >= iti->info.time_to_die)
	{
		// pthread_mutex_lock(&iti->info.printf_mtx);
		// printf("%d\n", iti->philo_index);
		// printf("\033[1;31m" "last_time_eaten %ld\n" "\033[0m", iti->last_time_eaten);
		// printf("\033[1;31m" "current_time %ld\n" "\033[0m", get_current_time());
		// printf("time to die %ld\n", iti->info.time_to_die);
		// printf("\033[1;31m" "%ld\n\n" "\033[0m", get_current_time() - ft_getters_value(iti->last_time_eaten, &iti->last_time_eaten_mtx));
		// pthread_mutex_unlock(&iti->info.printf_mtx);
		// printf("\033[1;31m" "%ld last time has eating\n" "\033[0m", get_current_time() - ft_getters_value(iti->last_time_eaten, &iti->last_time_eaten_mtx));
		// my_printf(iti, "*** is dead ***\n");
		ft_setters(iti->stop_simulation, 1, &iti->info.stop_simulation_mtx);
		if (ft_getters(iti->info.eating_number, &iti->info.eating_number_mtx) == -1)
			ft_setters(iti->info.eating_number, -2, &iti->info.eating_number_mtx);
		pthread_mutex_lock(&iti->info.printf_mtx);
		printf("\033[1;31m%ld %d died\033[0m\n", get_current_time() - ft_getters(iti->starting_of_simulation, &iti->info.starting_of_simulation_mtx), iti->philo_index);
		pthread_mutex_unlock(&iti->info.printf_mtx);
		return (1);
	}
	return (0);
}

void	check_death_all(t_philo_s	*philos)
{
	t_philo_s	*iti;
	int			i;

	iti = philos;
	i = 0;
	// printf("%i %i\n", i, iti->info.philos);
	while (ft_getters(philos->philos_finished_eating, &philos->info.finished_mtx) != philos->info.philos && !ft_getters(philos->stop_simulation, &philos->info.stop_simulation_mtx))
	{
		i = 0;
		iti = philos;
		while (i < iti->info.philos)
		{
			if (ft_getters_value(iti->eating_counter, &iti->eating_counter_mtx) < ft_getters(iti->info.eating_number, &iti->info.eating_number_mtx) || ft_getters(iti->info.eating_number, &iti->info.eating_number_mtx) == -1)
			{
				if (check_if_dead(iti))
				{
					// printf("someone has dies\n");
					break;
				}
			}
			iti++;
			i++;
		}
	}
}

void	start_simulation(t_philo_s	*philos)
{
	int			i; 
	pthread_t	*threads;
	t_philo_s	*phis;

	i = 0;
	threads = philos->arr_thr;
	phis = philos;
	ft_setters(philos->starting_of_simulation, get_current_time(), &philos->info.starting_of_simulation_mtx);
	while (i < (philos->info).philos)
	{
		pthread_create(threads, NULL, eat_sleep_think, phis);
		phis++;
		threads++;
		i++;
	}
	if (philos->info.philos != 1)
		check_death_all(philos);
	join_thread(philos);
}

t_philo_s	*make_philos(pthread_t	*arr_thr, pthread_mutex_t	*forks, t_data	info)
{
	long			*philos_finished_eating;
	long			*starting_of_simulation;
	long			*stop_simulation;
	int				i;
	t_philo_s		*first;
	t_philo_s		*philos;

	i = 1;
	philos_finished_eating = malloc(sizeof(long));
	starting_of_simulation = malloc(sizeof(long));
	stop_simulation = malloc(sizeof(long));
	first = malloc(sizeof(t_philo_s)*info.philos);
	pthread_mutex_init(&info.stop_simulation_mtx, NULL);
	pthread_mutex_init(&info.finished_mtx, NULL);
	pthread_mutex_init(&info.starting_of_simulation_mtx, NULL);
	pthread_mutex_init(&info.printf_mtx, NULL);
	pthread_mutex_init(&info.eating_number_mtx, NULL);
	*philos_finished_eating = 0;
	*stop_simulation = 0;
	*starting_of_simulation = 0;
	philos = first;
	give_forks(philos, forks, info.philos);
	while (i <= info.philos)
	{
		pthread_mutex_init(&philos->eating_counter_mtx, NULL);
		pthread_mutex_init(&philos->last_time_eaten_mtx, NULL); 
		philos->philo_index = i;
		philos->info = info;
		philos->philos_finished_eating = philos_finished_eating;
		philos->eating_counter = 0;
		philos->arr_thr = arr_thr;
		philos->stop_simulation = stop_simulation;
		philos->starting_of_simulation = starting_of_simulation;
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