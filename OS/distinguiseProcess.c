#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        int i = 1;
        while (i < 5) {
            printf("Hello from the child process %d!\n", i);
            i++;
        }
        exit(EXIT_SUCCESS);
    } else {
        printf("Hello from start parent!!\n");
        int status;
        (void)waitpid(pid, &status, 0);
        printf("Hello from end parent!!\n");
    }
    return EXIT_SUCCESS;
}
