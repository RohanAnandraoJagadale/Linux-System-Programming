// Client for shared memory

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
    char *ptr = NULL;

    printf("Client application running...\n");

    shmid = shmget(Key,shmsize,0666);

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared memory attached succesfully...\n");
    }

    return 0;
}
