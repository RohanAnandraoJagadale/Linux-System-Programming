#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


// void *______(void * ______)  prototype
// {}

void * ThreadProc(void *ptr)    // call back function
{
    int i = 0;

    for(i = 1; i < 1000; i++)
    {
        printf("Thread with counter : %d\n",i);
    }    
}

int main()
{
    pthread_attr_t TID;

    int ret = pthread_create(&TID,    //Address of pthread_attr_t structure object // id return value hetnar
                             NULL,    // Thread attributes                         //
                             ThreadProc,  // Address of callback function          // thread create jhalyav treadproc la call karnar
                             NULL);    // Parametes to callback function           //

    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %d\n",TID);

    printf("End of main thread\n");

    return 0;
}