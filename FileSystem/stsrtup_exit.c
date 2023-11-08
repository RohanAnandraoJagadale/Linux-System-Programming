//Program to demostrate startup and exit using #pragma.
#include<stdio.h>
void fun();
void sun() ;

void fun()
{
    printf("\nIn fun");
    exit(0);
}

void sun()
{
    printf("\nIn sun");
}

#pragma startup fun   // main function chya adhi fun call honar

#pragma exit sun      // main nantar call honar

int main()
{
    printf("\nIn main\n");
    return 0;
}

