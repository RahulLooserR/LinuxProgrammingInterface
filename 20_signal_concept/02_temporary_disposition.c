/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 02_temporary_disposition.c
 * Created on    : Saturday 30 November 2019 12:54:38 PM IST
 * Last modified : Saturday 30 November 2019 02:09:48 PM IST
 * Description   : temporary installing and removing signal disposition.
 * 					
 * 				   It is not possible to use signal() to retrieve the 
 * 				   current disposition of a signal without at the same
 * 				   time changing that disposition. To do that, 
 * 				   we must use sigaction(). 
 * ***********************************************************************/
	
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int flag = 0;

// signal handler
void newhandler (int sig)
{
	flag++;
	printf ("Signal caught SIGINT with sig_no: %d\n	\
			setting flag to %d\n", sig, flag);
}

int main()
{
	void (*oldhandler)(int); // function pointer to store old signal
	
	printf ("Installing handler for SIGINT\n");
	oldhandler = signal(SIGINT, newhandler);
	if (oldhandler == SIG_ERR){
		perror ("Error Signal !\n");
		exit (1);
	}

	while(1){
		if (flag == 5)
			break;
	}
	
	printf ("handler removed\n");
	if (signal(SIGINT, oldhandler) == SIG_ERR){
		perror ("Error Signal !\n");
		exit (1);
	}

	while (1);

	return 0;
}
