// Server for shared memory

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/stat.h>
#include<sys/shm.h>

int main()
{
    int shmid = 0;
    int shmsize = 100;
    int Key = 1234;

    printf("Server application running...\n");

    shmid = shmget(Key,shmsize,IPC_CREAT | 0666);

    printf("Shared memory allocated succesfully...\n");

    return 0;
}


// ipcs command details pahanyasathi
// ipcs -m = shared memory chi mahiti diste