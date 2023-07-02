// note run in linux

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork(); // create a child process

    if (pid == -1)
    { // check for errors
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    { // child process
        printf("Child process with PID %d has been created\n", getpid());
        sleep(2); // sleep for 2 seconds
        printf("Child process with PID %d is now terminating\n", getpid());
        exit(EXIT_SUCCESS);
    }
    else
    { // parent process
        printf("Parent process with PID %d has created a child with PID %d\n", getpid(), pid);
        int status;
        wait(&status); // wait for child process to terminate
        printf("Child process with PID %d has terminated with status %d\n", pid, WEXITSTATUS(status));
    }

    return 0;
}
