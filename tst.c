/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:54:47 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/10 11:51:22 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct t_data
{
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	int fise;
}t_data;


void	*increment(void *arg)
{
	t_data *data;
	int i = 0;
	data = (t_data *)arg;
	pthread_mutex_lock(data->left);
		printf("taking left\n");
	pthread_mutex_lock(data->right);
		printf("taking right\n");
		if (data->fise == 0)
			printf("the first philo is eating\n");
		else if (data->fise == 1)
			printf("the second philo is eating\n");
		usleep(1000000);
		data->fise = 1;
	pthread_mutex_unlock(data->right);
	pthread_mutex_unlock(data->left);
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t thread_id;
	pthread_t thread_id1;
	pthread_mutex_t left;
	pthread_mutex_t right;
	t_data data;

	// pthread_mutex_init(&left, NULL);
	// pthread_mutex_init(&right, NULL);
	data.left = &left;
	data.right = &right;
	data.fise = 0;
	int result = pthread_create(&thread_id, NULL, increment, &data);
	// data.fise = 1;
	int resulta = pthread_create(&thread_id1, NULL, increment, &data);
	pthread_join(thread_id, NULL);
	pthread_join(thread_id1, NULL);
	// printf("%i\n", counter);
	return (0);
}