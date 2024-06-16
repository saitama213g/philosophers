#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

long time_to_sleep = 5;

void    *print_sleeping(void *args)
{
    struct timeval tv;
    long timestamp1;
    long timestamp2;

    gettimeofday(&tv, NULL);
    timestamp1 = tv.tv_sec*1000000 + tv.tv_usec;
    timestamp2 = timestamp1;
    while (timestamp2 - timestamp1 < 1)
    {
        gettimeofday(&tv, NULL);
        timestamp2 = tv.tv_sec*1000000 + tv.tv_usec;
        printf("is sleeping\n");
    }
}

int main(void)
{
    struct timeval  tv;
    pthread_t       thread;
    int             timestamp1;
    int             timestamp2;
    int             duration;

    print_sleeping(NULL);
    // gettimeofday(&tv, NULL);
    // printf("%li\n", (tv.tv_sec*1000000 + tv.tv_usec)/1000000/60/60/24/30/12);
    // pthread_create(&thread, NULL, &print_sleeping, NULL);
    // pthread_join(&thread, NULL);
    // printf("yes");
    // sleep(6);
}