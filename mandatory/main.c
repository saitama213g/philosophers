/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:04:16 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/15 12:55:19 by aet-tale         ###   ########.fr       */
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
	int				time_to_think_counter;
	int				time_to_die_counter;
	int				time_to_eat;
	int				think_sleep_eat;
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
	philo_info	*info;

	info = (philo_info *)param;
	if (info->time_to_die_counter - info->time_to_think_counter <= 0)
	{
		printf("philo number %i has died", info->number);
		exit(0);
		return NULL;
	}
	pthread_mutex_lock(info->fork1);
		printf("philo number %i has taken a fork \n", info->number);
	pthread_mutex_lock(info->fork2);
		printf("philo number %i has taken a fork \n", info->number);
		// make time_to_die reset
		info->time_to_die_counter = info->time_to_die;
		printf("philo number %i is eating \n", info->number);
		// usleep the time of eating and make it eating
		// usleep(info->time_to_eat);
		usleep(200);
		info->time_to_die_counter -= info->time_to_eat;
		usleep(200);
		printf("philo number %i is sleeping \n", info->number);
		info->time_to_die_counter -= info->time_to_sleep;
		info->time_to_think_counter = 0;
	pthread_mutex_unlock(info->fork2);
	pthread_mutex_unlock(info->fork1);
	printf("philo number %i is thinking\n", info->number);
	info->time_to_think_counter++;
	// info->time_to_think++;
	// then think until forks are available to use or a philo dies
	return (eat_sleep_think(info));
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
		info.time_to_die_counter = info.time_to_die;
		info.time_to_sleep = data->time_to_sleep;
		info.time_to_think_counter = 0;
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