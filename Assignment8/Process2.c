#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int Ret = 0;
    int Status = 0;

    Ret = fork();

    if(Ret == 0)
    {
        execl("./Process3","NULL",NULL);
    }
    else
    {
        printf("Process2 is running with PID : %d\n",getpid());
    }
    wait(&Status);

    return 0;
}
