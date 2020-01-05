/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 01_changing_signal_disposition.c
 * Created on    : Saturday 30 November 2019 12:37:57 PM IST
 * Last modified : Sunday 05 January 2020 08:57:14 PM IST
 * Description   : changing signal disposition using signal() system call
 *                 void (*signal (int sig, void (*handler)(int))(int)
 *                 			returns-> signal disposition
 *                 			returns-> SIG_ERR (on error)
 *				   
 *				   if we use typedef, then same prototype can be written,
 *				   typedef void (*sighandler_t)(int);
 *
 *				   sighandler_t signal(int sig, sighandler_t handler);
 *
 * ***********************************************************************/
	

#include <signal.h>
#include "utilities.h"

// signal handler function
static void sig_handler (int sig)
{
	printf ("Signal SIG_INT caught with sig_no: %d\n", sig);
}

int main()
{	
	// installing signal handler
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		error_exit("Error signal !!\n");

	while (1);

	return 0;
}
