#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/stat.h>

// client for named pipe

int main()
{
    int fd = 0;

    char *path = "/tmp/mypipe";   // temporary file banavnyathi tmp madhe baanavli
    char Buffer[100];

    printf("Client is running and writing the data into named pipe....\n");
    fd = open(path,O_WRONLY);

    read(fd,Buffer,10);

    printf("Data from pipe is : %s\n",Buffer);

    return 0;
}