#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t childPid = fork();
    if (childPid == 0) {
        // child process
        printf("I am the process #%d of parent %d ..", getpid(), getppid());
        printf("But the parent give me #%d\n", childPid);
        exit(0);
    } else if (childPid > 0) {
        wait(&childPid);
        // parent process.
        printf("I am the process #%d of parent %d ..", getpid(), getppid());
        printf("I am process #%d\n", getpid());
        exit(0);
    } else {
        fprintf(stderr, "Sorry process cannot be created");
        return -1;
    }
}
