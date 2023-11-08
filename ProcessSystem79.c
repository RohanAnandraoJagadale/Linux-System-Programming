#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/stat.h>

// server for named pipe

int main()
{
    int fd = 0;

    char *path = "/tmp/mypipe";   // temporary file banavnyathi tmp madhe baanavli

    fd = mkfifo("path",0666);
    if(fd == -1)
    {
        printf("Unable to create named file\n");
        return -1;
    }

    printf("Server is running and writing the data into named pipe....\n");
    fd = open(path,O_WRONLY);

    write(fd,"Marvellous",10);

    close(fd);
    
    unlink(path);

    printf("Data succesfully written in the pipe\n");

    return 0;
}