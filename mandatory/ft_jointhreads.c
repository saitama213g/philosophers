#include "philo.h"

void join_thread(t_philo_s	*philos)
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
