#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "../name.c"

#define SHM_SIZE 1024 // size of shared memory segment

int main()
{
    int shmid;
    key_t key;
    char *shm_ptr;

    // Generate a unique key for the shared memory segment
    key = ftok("shmfile", 'R');
    if (key == -1)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a new shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the process's address space
    shm_ptr = (char *)shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)-1)
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Write some data to the shared memory segment
    sprintf(shm_ptr, "Hello, shared memory!");

    // Detach the shared memory segment from the process's address space
    shmdt(shm_ptr);

    // Re-attach the shared memory segment to read the data
    shm_ptr = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (shm_ptr == (char *)-1)
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Read the data from the shared memory segment
    printf("Data read from shared memory: %s\n", shm_ptr);

    // Detach the shared memory segment from the process's address space
    shmdt(shm_ptr);

    // Delete the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    name("2", "Suyash Shrestha", 22, 'B');

    return 0;
}
