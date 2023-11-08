#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int cpid = 0;
    int Exit_Status = 0;

    Ret = fork();

    if(Ret == 0)  // Child  
    {
        execl("./ChildProcess","NULL",NULL);
        
    }
    else        // Parent
    {
        printf("Parent is running with PID : %d\n",getpid());
        cpid = wait(&Exit_Status);
        printf("Child process terminated hiving PID %d with exit status %d\n",cpid,Exit_Status);
        sleep(1000);
    }
    return 0;
}
