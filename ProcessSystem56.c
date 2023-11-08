#include<stdio.h>

int main()
{
    printf("Inside child process - PID of parent process is : %d\n",getpid());

    return 0;
}