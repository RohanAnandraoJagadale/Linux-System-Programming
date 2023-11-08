#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int Ret = 0;
    int Status1 = 0;
    
    Ret = fork();

    if(Ret == 0)
    {
	printf("Process4 is running with PID : %d\n",getpid());
    }
    
    wait(&Status1);
    
    wait();
}
