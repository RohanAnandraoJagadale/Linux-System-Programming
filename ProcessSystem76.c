#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


int Counter = 0;  //(room)  Shared resource

void * ThreadProc(void *ptr)    // call back function
{
    int i = 0;
    Counter++;
    printf("Thread execution with counter : %d\n",Counter);
    for(i = 0; i < 0xFFFFFFFF; i++);   // kapde change  //Finite loop  
    // execution la vel lagtoy 1 min
    printf("Thread completed with counter : %d\n",Counter);
    pthread_exit(NULL);

}
// problem statement code

int main()
{
    pthread_t TID1;
    pthread_t TID2;
    int ret = 0;
    

    ret = pthread_create(&TID1,    //Address of pthread_attr_t structure object // id return value hetnar
                             NULL,    // Thread attributes                         //
                             ThreadProc,  // Address of callback function          // thread create jhalyav treadproc la call karnar
                             NULL);    // Parametes to callback function           //

    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    ret = pthread_create(&TID2,    //Address of pthread_attr_t structure object // id return value hetnar
                             NULL,    // Thread attributes                         //
                             ThreadProc,  // Address of callback function          // thread create jhalyav treadproc la call karnar
                             NULL);    // Parametes to callback function           //

    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
  
    printf("End of main thread\n");

    return 0;
}