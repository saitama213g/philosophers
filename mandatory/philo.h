/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:05:24 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/30 15:36:41 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct t_data
{
	int		philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long		*eating_number;
}t_data;

typedef struct t_philo_s
{
	int				philo_index;
	long			*stop_simulation;
	t_data			info;
	pthread_t		*arr_thr;
	long			*philos_finished_eating;
	long			last_time_eaten;
	// long			last_time_eaten;
	long			eating_counter;
	long			*starting_of_simulation;
	pthread_mutex_t	*forks;
	pthread_mutex_t *fork1;
	pthread_mutex_t *fork2;
	pthread_mutex_t	*printf_mtx;
	pthread_mutex_t	*is_dead_mtx;
	pthread_mutex_t	*finished_mtx;
	pthread_mutex_t	*stop_simulation_mtx;
	pthread_mutex_t	*eating_counter_mtx;
	pthread_mutex_t	*last_time_eaten_mtx;
	// long			is_dead;
}t_philo_s;

int		ft_atoi(char *s);
int		ft_isdigit(int c);
t_data	give_data(int ac, char **av);
void	give_forks(t_philo_s *philos, pthread_mutex_t *forks, int philos_nmbr);
long	ft_getters(long *x, pthread_mutex_t *mtx);
void	ft_setters(long *x, long value, pthread_mutex_t *mtx);
void	join_thread(t_philo_s	*philos);
void	ft_setters_value(long x, long value, pthread_mutex_t *mtx);
long	ft_getters_value(long x, pthread_mutex_t *mtx);

# endif