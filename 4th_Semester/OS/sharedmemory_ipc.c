#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    // Creates shared memory segment with key 2345, having size 1024 bytes.
    // IPC_CREAT is used to create the shared segment if it does not exist.
    // 0666 are the permisions on the shared segment
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    printf("Key of shared memory is %d\n", shmid);

    // Process attached to shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    // this prints the address where the segment is attached with this process
    printf("Process attached at %p\n", shared_memory); 
    printf("Enter some data to write to shared memory\n");
    // get some input from user
    read(0, buff, 100);
    // Write data in the shared memory
    strcpy(shared_memory, buff);
    printf("You wrote : %s\n", (char *)shared_memory); // Displays the data in shared memory
}
