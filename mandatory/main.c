/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:04:16 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/12 15:43:58 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct philo_info
{
	int number;
	pthread_mutex_t *fork1;
	pthread_mutex_t *fork2;
	int				*locked_forks;
	int 			time_to_die;
	int 			time_to_sleep;
}philo_info;


// typedef struct t_info
// {
	
// }

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

void	*eat_sleep_think(void	*param)
{
	int i = 0;
	philo_info	 *info;
	info = (philo_info *)param;
	if (info->time_to_die == 0)
		
	pthread_mutex_lock(info->fork1);
	pthread_mutex_lock(info->fork2);
		// make time_to_die reset
		// make_fork_locked in your own data
		printf("philo number %i is eating \n", info->number);
		// sleep the time of eating
	pthread_mutex_unlock(info->fork2);
	pthread_mutex_unlock(info->fork1);
	// then think until forks are available to use or a philo dies
	return (NULL);
}

philo_info	give_info(int i, pthread_mutex_t *forks, int number_ph)
{
	philo_info info;

	info.number = i;
	info.fork1 = &forks[i];
	if (i + 1 == number_ph)
		info.fork2 = &forks[0];
	return (info);
}


void	make_threads(pthread_t *arr_thr, pthread_mutex_t *forks, t_data *data)
{
	int			i;
	philo_info	info;

	i = 0;
	while (i < data->philos)
	{
		info = give_info(i, forks, data->philos);
		info.time_to_die = data->time_to_die;
		info.time_to_sleep = data->time_to_sleep;
		pthread_create(&arr_thr[i], NULL, eat_sleep_think, &info);
		pthread_join(arr_thr[i], NULL);
		i++;
	}
}

// void make_threads(pthread_t *arr_thr, int number_ph)
// {
// 	int i = 0;
// 	while (i < number_ph)
// 	{
		
// 		i++;
// 	}
// }

void philo(int ac, char **av)
{
	t_data			data;
	pthread_t		*arr_thr;
	pthread_mutex_t	*forks;

	data = give_data(ac, av);
	arr_thr = malloc(sizeof(pthread_t)*data.philos);
	forks = malloc(sizeof(pthread_mutex_t)*data.philos);
	make_threads(arr_thr, forks, &data);
	// make_philos(data.philos);
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