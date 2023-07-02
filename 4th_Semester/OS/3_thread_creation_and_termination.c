#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    printf("Child thread executing...\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;
    int thread_create_result;
    int thread_join_result;

    // Create a new thread
    thread_create_result = pthread_create(&thread, NULL, thread_function, NULL);
    if (thread_create_result != 0)
    {
        printf("Error: Thread creation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Main thread waiting for child thread to finish...\n");

    // Wait for the thread to finish executing
    thread_join_result = pthread_join(thread, NULL);
    if (thread_join_result != 0)
    {
        printf("Error: Thread join failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Child thread has finished executing and has been joined with the main thread\n");

    return 0;
}
