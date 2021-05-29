/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : sigaction.c
 * Created on    : Saturday 18 April 2020 12:53:53 PM IST
 * Last modified : Saturday 18 April 2020 02:07:44 PM IST
 * Description   : 
 * ***********************************************************************/

#include <stdio.h>
#include <signal.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void my_handler(int sigtype)
{
	printf("got signal: %d\n", sigtype);
}

int main()
{
	struct sigaction act;
	int n, p[2]; 
	char buf[100];

	//creating pipe
	pipe(p);

	act.sa_handler = my_handler;
	sigemptyset(&act.sa_mask);
	//act.sa_flags = 0;    // return read error
	act.sa_flags = SA_RESTART; // restart the read system call, no error

	sigaction(SIGINT, &act, NULL);

	while(1){
		n = read(p[0], buf, 100);
		printf("read returned %d, errno %d\n", n, errno);
	}

	return 0;
}
