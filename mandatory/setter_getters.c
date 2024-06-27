#include "philo.h"

long	ft_getters(long *x, pthread_mutex_t *mtx)
{
	long n;

	n = -1;
	pthread_mutex_lock(mtx);
	n = *x;
	pthread_mutex_unlock(mtx);
	return (n);
}
void	ft_setters(long *x, int value, pthread_mutex_t *mtx)
{
	pthread_mutex_lock(mtx);
	*x = value;
	pthread_mutex_unlock(mtx);
}

long	ft_getters_value(long x, pthread_mutex_t *mtx)
{
	long	n;
    
	n = -1;
	pthread_mutex_lock(mtx);
	n = x;
	pthread_mutex_unlock(mtx);
	return n;
}
void	ft_setters_value(long x, long value, pthread_mutex_t *mtx)
{
	pthread_mutex_lock(mtx);
	x = value;
	pthread_mutex_unlock(mtx);
}
