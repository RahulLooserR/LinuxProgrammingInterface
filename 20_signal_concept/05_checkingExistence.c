/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 05_checkingExistence.c
 * Created on    : Wednesday 25 December 2019 11:07:18 PM IST
 * Last modified : Thursday 26 December 2019 10:49:12 PM IST
 * Description   : Checking exitence of process.
 * 				   kill(pid,0) sending NULL signal and checking for
 * 				   ERSCH error (no such process found)
 * ***********************************************************************/
#include <stdio.h>
#include <sys/types.h>  // for fork(), wait()
#include <sys/wait.h>   // wait()
#include <unistd.h>     // for fork()
#include <stdlib.h>     // exit()
#include <errno.h>      // constants ESRCH (no such process)

int var = 0;

static void sigchld_handler(int sig)
{
	printf ("SIGCHLD captured\n");
	var = 1;
}

int main()
{
	pid_t pid;
	int status;

	if ((pid = fork())== 0){
		printf ("Entered in child process\n");
		sleep(10);
	}
	else{
		if(signal(SIGCHLD, sigchld_handler) == SIG_ERR){
			perror("Error signal\n");
			exit(1);
		}
		printf("Entered in parent process: %d\n", getpid());
		printf("child pid: %d\n",pid);
		while(1){
			if(var)
				break;
		}
		
		kill(pid, SIGTERM);

		printf("Sending null signal to non-existing process\n");
		// sending SIGINT to child process
		if( (status = kill(pid, 0)) == ESRCH)
		{
			perror ("Process does not exists !\n");
			exit(1);
		}
		printf("Signal sent to: %d\nstatus: %d\n",pid, status);
	}
	
	return 0;
}

