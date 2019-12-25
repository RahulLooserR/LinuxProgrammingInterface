/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 04_sendingSignals.c
 * Created on    : Wednesday 25 December 2019 02:41:03 PM IST
 * Last modified : Wednesday 25 December 2019 10:10:16 PM IST
 * Description   : Sending signal from one process to another 
 * 				   process using kill()
 * 				   int kill (pid_t pid, int sig)
 * 				   pid > 0, signal sent to specific process with pid
 * 				   pid = 0, signal sent to every process of same process 
 * 				   			group including itself.
 * 				   pid < -1, ??
 * 				   pid = -1, signal to every process for which calling 
 * 				   			 process has permission. 
 * ***********************************************************************/

#include <stdio.h>
#include <sys/types.h>	// for fork(), wait()
#include <sys/wait.h> 	// wait()
#include <unistd.h>		// for fork()
#include <stdlib.h> 	// exit()
#include <errno.h>		// constants ESRCH (no such process)


int main()
{
	pid_t pid;
	int status;

	if ((pid = fork())== 0){
		printf ("Entered in child process\n");
		while(1);
	}
	else{
		printf("Entered in parent process: %d\n", getpid());
		printf("child pid: %d\n",pid);
		sleep(5);
		// sending SIGINT to child process
		if( kill(pid, SIGINT) == ESRCH){
			perror ("Error kill !\n");
			exit(1);
		}
	}
	//waiting for all child to terminate 
	if(waitpid(-1, &status,0) == pid){
	printf("child process terminated\n");
	}

	return 0;
}
