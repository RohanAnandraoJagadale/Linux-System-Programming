#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int ret = 0;

    ret = nice(0);

    printf("Current Priority of process is %d\n",ret); 

    ret = nice(10);
    printf("Current Priority of process is %d\n",ret);

    // -20 to 19
    // -20 is highest priority
    // 19 is lowest priority
    // 0 is default priority

    ret = nice(-1);
    printf("Current Priority of process is %d\n",ret);

    return 0;
}
