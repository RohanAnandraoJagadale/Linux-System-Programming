#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = 0;
	int fdnew = 0;

	fd = open("Demo.txt",O_RDONLY);
	printf("File opened with FD : %d\n",fd);

	fdnew = dup(fd);
	printf("Duplicate FD is : %d\n",fdnew);

	return 0;
}