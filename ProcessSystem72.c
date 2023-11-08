#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


// void *______(void * ______)  prototype
// {}

void * ThreadProc1(void *ptr)    // call back function
{
    printf("Inside thread 1\n");

    pthread_exit(NULL); 
}

void * ThreadProc2(void *ptr)    // call back function
{
    printf("Inside thread 2\n");
       
    pthread_exit(NULL); 
}


int main()
{
    pthread_t TID1;
    pthread_t TID2;

    int ret1 = 0, ret2 = 0;

    ret1 = pthread_create(&TID1,    //Address of pthread_attr_t structure object // id return value hetnar
                             NULL,    // Thread attributes                         //
                             ThreadProc1,  // Address of callback function          // thread create jhalyav treadproc la call karnar
                             NULL);    // Parametes to callback function           //

    if(ret1 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %d\n",TID1);

    pthread_join(TID1,NULL);

    ret2 = pthread_create(&TID2,    //Address of pthread_attr_t structure object // id return value hetnar
                             NULL,    // Thread attributes                         //
                             ThreadProc2,  // Address of callback function          // thread create jhalyav treadproc la call karnar
                             NULL);    // Parametes to callback function           //

    if(ret2 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %d\n",TID2);

    pthread_join(TID2,NULL);

    printf("End of main thread\n");

    pthread_exit(NULL);
    return 0;
}