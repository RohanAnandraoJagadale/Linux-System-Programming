// Write a program which create three level process hierarchy where 
//process 1 creates process 2 and it internally creates process 3.

#include<stdio.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int cpid = 0;
    int Exit_Status = 0;
    Ret = fork();

    if(Ret == 0)
    {
        execl("./Hierarchy","NULL",NULL);

    }
    else
    {
        printf("\nProcess1 is running with PID : %d\n",getpid());
    }

    return 0;
}