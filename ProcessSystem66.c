#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int ret1 = 0, ret2 = 0;

    ret1 = fork();
    if(ret1 == 0)
    {
        execl("./ProcessSystem64","NULL",NULL);
    }

    ret2 = fork();
    if(ret2 == 0)
    {
        execl("./ProcessSystem65","NULL",NULL);
    }    

    return 0;
}