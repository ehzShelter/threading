#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid1 = fork();
    pid_t pid2 = fork();
    pid_t pid3 = fork();

    printf("%d pid1\n", pid1);
    printf("%d pid1\n", pid2);
    printf("%d pid1\n", pid3);

    return 0;
}
