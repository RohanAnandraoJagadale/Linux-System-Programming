// Write a program which creates two processes as process2 and 
// process3 and our parent process terminates till both the processes terminates.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int ret1 = 0, ret2 = 0;
    int pid1,pid2;
    int status1,status2;


    ret1 = fork();
    if(ret1 == 0)
    {
        execl("./ProcessSystem2","NULL",NULL);
    }

    wait(&status1);

    ret2 = fork();
    if(ret2 == 0)
    {
        execl("./ProcessSystem3","NULL",NULL);
    }    

    wait(&status2);
    return 0;
}