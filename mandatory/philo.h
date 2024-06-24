/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:05:24 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/23 18:50:07 by aet-tale         ###   ########.fr       */
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
	int		eating_number;
}t_data;

typedef struct t_philo_s
{
	int				philo_index;
	pthread_t		*arr_thr;
	pthread_mutex_t	*forks;
	pthread_mutex_t *fork1;
	pthread_mutex_t *fork2;
	pthread_mutex_t	*x_mutex;
	pthread_mutex_t	*printf_mtx;
	t_data			info;
	int				*all_have_eating;
	int				*all_are_created;
}t_philo_s;

int		ft_atoi(char *s);
int		ft_isdigit(int c);
t_data	give_data(int ac, char **av);
void	give_forks(t_philo_s *philos, pthread_mutex_t *forks, int philos_nmbr);
int		ft_getters(int *x, pthread_mutex_t *mtx);
void	ft_setters(int *x, int value, pthread_mutex_t *mtx);
void join_thread(t_philo_s	*philos);

# endif