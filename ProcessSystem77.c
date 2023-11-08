#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


int Counter = 0;  //(room)  Shared resource

pthread_mutex_t lock;    //kulup lavane  // doganahi vaparta yete

void * ThreadProc(void *ptr)    // call back function
{
    pthread_mutex_lock(&lock);  // kadi lava lock
// kernel chya kde control asto mutex cha . kam hoi paryant wait. tread2 rest pahilyach kaam hoi paryant
// pahilyach kaam jhalyav karnel notify by signal to thread2.
    int i = 0;
    Counter++;
    printf("Thread execution with counter : %d\n",Counter);
    for(i = 0; i < 0xFFFFFFFF; i++);   // kapde change  //Finite loop  // 2min lagtat execution la
    printf("Thread completed with counter : %d\n",Counter);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);

}
// problem statement code

int main()
{
    pthread_t TID1;
    pthread_t TID2;
    int ret = 0;
    
    pthread_mutex_init(&lock,NULL);  // initializing

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

    pthread_mutex_destroy(&lock);
// os kade eakach kulup aste tyamule destroy karne  
    printf("End of main thread\n");

    return 0;
}