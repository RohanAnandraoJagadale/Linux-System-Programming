// This program demonstates temorary file creation

#include<stdio.h>

int main()
{
FILE *fp;

fp = tmpfile();

if(fp == NULL)
{
	printf("Unable to create temorary file.\n");
}
// tem chya aat file bante
// Now we can use this fp for further file operation
// automatic delete 
return 0;
}
