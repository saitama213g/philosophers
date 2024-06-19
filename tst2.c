#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

long time_to_sleep = 5;

void    *increment(void *args)
{
    pthread_mutex_t *t;
    int i = 0;
    t = (pthread_mutex_t*)args;
    pthread_mutex_lock(t);
    printf("hello world from thread 1\n");
    sleep(7);
    pthread_mutex_unlock(t);
    return (NULL);
}
void    *say_hello(void *args)
{
    pthread_mutex_t *t;
    int i = 0;
    t = (pthread_mutex_t*)args;
    // pthread_mutex_lock(t);
    // printf("hello world from thread 2\n");
    // pthread_mutex_unlock(t);
    printf("waiting for mutex to get unlocked\n");
    return (NULL);
}
int main(void)
{
	pthread_t thread_id;
	pthread_t thread_id1;
    pthread_mutex_t lock;


    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread_id, NULL, increment, &lock);
    pthread_create(&thread_id1, NULL, say_hello, &lock);
    pthread_join(thread_id, NULL);
    pthread_join(thread_id1, NULL);

    // print_sleeping(NULL);
    // gettimeofday(&tv, NULL);
    // printf("%li\n", (tv.tv_sec*1000000 + tv.tv_usec)/1000000/60/60/24/30/12);
    // pthread_create(&thread, NULL, &print_sleeping, NULL);
    // printf("yes");
    // sleep(6);
}
