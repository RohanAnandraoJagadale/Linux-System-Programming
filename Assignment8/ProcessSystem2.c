#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    printf("Process2 is running with PID : %d\n",getpid());
    
    return 0;
}
