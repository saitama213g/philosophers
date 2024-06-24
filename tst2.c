#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 1000000

// Global mutex
pthread_mutex_t print_mutex;

void* thread_function(void* arg) {
    // Lock the mutex before printing
    // pthread_mutex_lock(&print_mutex);
    
    // Critical section: calling printf
    printf("Thread %ld is running \n", (long)arg);
    
    // Unlock the mutex after printing
    // pthread_mutex_unlock(&print_mutex);
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    long i;

    // Initialize the mutex
    pthread_mutex_init(&print_mutex, NULL);

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }

    // Join threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&print_mutex);

    return 0;
}