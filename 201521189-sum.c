#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int glob = 0;
int glob2 = 101;

int main( void)
{
	int var;
	pid_t pid;
	
	printf("before fork\n");
	
	if(( pid = vfork()) < 0)
	{
		printf("fork error");
	}
	else if(pid == 0)
	{
		for(glob=0; glob=100; glob++)
		_exit(0);
	}
	if(( pid = vfork()) < 0)
	{
		printf("fork error");
	}
	else if(pid == 0)
	{
		for(glob2=101; glob2=200; glob++)
		_exit(0);
	}
	printf("glob = %d, glob2 = %d, glob+glob2= %d\n", glob, glob2, glob+glob2);
	exit(EXIT_SUCCESS);
}

