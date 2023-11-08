// Write a program which creates three different processes 
// internally as process2, process3, process4.

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
        execl("./Process2","NULL",NULL);
    }
    else
    {
        printf("Process1 is running with PID : %d\n",getpid());
    }

    wait(&Status);

    return 0;
}