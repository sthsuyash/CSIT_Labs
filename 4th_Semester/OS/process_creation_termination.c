#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void createProcess()
{
    /*
    fork function creates a separate, duplicate process of the main process.
            Main Process (or Parent Process)
                          |
                        fork()
                |                     |
        Parent Process          Child Process

    Both parent and child will have different process id
    *getpid() – this function returns the process id of the calling process, its syntax is, pid_t getpid()
    *getppid() – this function returns the parent process id in which the function is calling, its syntax is, pid_t getppid()
    */

    pid_t pid = fork(); // pid_t is a process identification datatype in C

    // fork() duplicates this if else conditional statement.
    // At first, pid will be anything but 0 executing parent task, then then statement will rerun creating a child process whoose pid will be 0 executing child task.
    if (pid == 0)
    {
        printf("Child task executed with => Parent_PID: %d Child_PID: %d\n", getppid(), getpid());
    }
    else if (pid > 0)
    {
        printf("Parent task executed with => PID: %d\n", getpid());
        wait(NULL);
    }
    else
    {
        printf("Unable to create child process.\n");
    }
}

void terminateProcess() {
   printf("Called cleanup function - terminateProcess()\n");
   exit (0);
   return;
}

int main()
{
    createProcess();
    terminateProcess();
    printf("This won't run as process already terminated");
    return 0;
}
