#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int PID = 0;
    int PPID = 0;

    PID = getpid();
    printf("PID of running process is : %d\n",PID);

    PPID = getppid();
    printf("PPID of parent process is : %d\n",PPID);  
    // terminal cha PPID


    return 0;
}