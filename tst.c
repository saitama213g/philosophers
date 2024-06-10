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

int		counter = 0;
pthread_mutex_t lock;

void	*increment(void *arg)
{
	// int i = 0;
	// pthread_mutex_lock(&lock);
	// while (i < 10000)
	// {
	for(int i = 0; i<100000 ;i++)
		counter++;
	// 	i++;
	// }
	// pthread_mutex_unlock(&lock);
	// printf(" i %i\n", i);
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t thread_id;
	pthread_t thread_idi;

	pthread_mutex_init(&lock, NULL);
	int result = pthread_create(&thread_id, NULL, increment, NULL);
	int resulta = pthread_create(&thread_id, NULL, increment, NULL);
	pthread_join(thread_id, NULL);
	pthread_join(thread_idi, NULL);
	printf("%i\n", counter);
	return (0);
}