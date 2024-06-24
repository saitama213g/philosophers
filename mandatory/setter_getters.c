#include "philo.h"

int	ft_getters(int *x, pthread_mutex_t *mtx)
{
	int n;
    

	n = -1;
	pthread_mutex_lock(mtx);
	n = *x;
	pthread_mutex_unlock(mtx);
	return n;
}
void	ft_setters(int *x, int value, pthread_mutex_t *mtx)
{
	pthread_mutex_lock(mtx);
	*x = value;
	pthread_mutex_unlock(mtx);
}
