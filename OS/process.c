#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int value = 5;

int main()
{
    pid_t pid = fork();

    if (pid == 0) {
        value += 15;
        return 0;
    } else if (pid > 0) {
        printf("Parent : value = %d", pid);
        return 0;
    }
}
