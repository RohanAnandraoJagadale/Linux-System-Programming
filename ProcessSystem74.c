#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


// void *______(void * ______)  prototype
// {}

void * ThreadProc(void *ptr)    // call back function
{
    printf("Value received from main thread is : %d\n",(int)ptr);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int no = 11;

    ret = pthread_create(&TID,    //Address of pthread_attr_t structure object // id return value hetnar
                             NULL,    // Thread attributes                         //
                             ThreadProc,  // Address of callback function          // thread create jhalyav treadproc la call karnar
                             (int *)no);    // Parametes to callback function           //
#
    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %d\n",TID);

    pthread_join(TID,NULL);

    printf("End of main thread\n");

    return 0;
}
