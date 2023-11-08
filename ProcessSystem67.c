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
        execl("./ProcessSystem64","NULL",NULL);
    }

    wait(&status1);

    ret2 = fork();
    if(ret2 == 0)
    {
        execl("./ProcessSystem65","NULL",NULL);
    }    

    wait(&status2);
    return 0;
}