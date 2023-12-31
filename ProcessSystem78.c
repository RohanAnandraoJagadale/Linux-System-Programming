#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

// Unnamed pipe

int main()
{
    int FD[2];
    int iRet = 0;
    char Arr[] = "Marvellous";
    char Buffer[512];

    pipe(FD);

    iRet = fork();

    if(iRet == 0)    // child process
    {
        printf("Parent process scheduled for writing into pipe\n");
        close(FD[0]);
        write(FD[1],Arr,strlen(Arr));
        exit(0);
    }
    else  // parent process
    {
        printf("Parent process scheduled for reading from pipe\n");
        close(FD[1]);
        read(FD[0],Buffer,sizeof(Buffer));
        printf("Data from PIPE is : %s\n",Buffer);
    }

    return 0;
}
