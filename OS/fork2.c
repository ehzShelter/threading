#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void dummy()
{
    printf("process 1 %d\n", fork());
    printf("process 2 %d\n", fork());
}

int main(void)
{
    printf("Starting from the main function %d\n", getpid());
    dummy();
    return 0;
}
