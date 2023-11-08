#include<stdio.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    
    Ret = fork();

    if(Ret == 0)
    {
        printf("Process3 is running with PID %d\n",getpid());

    }
    else
    {
        printf("\nProcess2 is running with PID : %d\n",getpid());
    }

    return 0;
}