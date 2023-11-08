// Write a program which creates two processes.
// Process 1 count number of capital characters from demo.txt file
// and process 2 count number of capital characters from hello.txt file.
// Both processes writes its count.txt file

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int ret1 = 0, ret2 = 0;

    ret1 = fork();
    if(ret1 == 0)
    {
        execl("./CountSmall","NULL",NULL);
    }
    wait(&ret1);

    ret2 = fork();
    if(ret2 == 0)
    {
        execl("./CountCap","NULL",NULL);
    }    
    wait(&ret2);
    return 0;
}