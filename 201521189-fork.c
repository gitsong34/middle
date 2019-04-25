#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	int pfds[2];
	char buf[30];
	pipe(pfds);
	
	if(!fork())
	{
		printf(" CHILD: writing to the pipe\n");
		write(pfds[1], "201521189,songjaewon", 21);
		printf(" CHILD: exiting\n");
		exit(0);
	}
	else
	{
		printf("PARENT: reading from pipe\n");
		read(pfds[0], buf, 21);
		printf("PARENT: read \"%s\"\n", buf);
		wait(NULL);
	}
	return 0;
}

