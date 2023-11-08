// Write a program in which parent process waits till its child process terminates.

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
        execl("./ChildProcess","NULL",NULL);

    }
    else
    {
        printf("Parent is running with PID : %d\n",getpid());
        cpid = wait(&Exit_Status);
        printf("Child process is terminated having PID %d with exit status %d\n",cpid,Exit_Status);
    }

    return 0;
}