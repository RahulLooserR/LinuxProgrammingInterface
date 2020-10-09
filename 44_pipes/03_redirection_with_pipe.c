/*    
 * simulate below command    
 * ls -l | wc -l > numberofLines.txt    
 * using fork(), exec(), pipe(), and dup()/dup2()    
 */ 

#include "utilities.h"
#include "pipes.h"


int
main(int argc, char *argv[])
{
	int pfd[2], file_fd;
	if (pipe(pfd) == -1)
		error_exit("pipe");
	/* Pipe file descriptors */
	/* Create pipe */
	switch (fork()) {
		case -1:
			error_exit("fork");
		case 0:
			/* First child: exec 'ls' to write to pipe */
			if (close(pfd[0]) == -1)
				/* Read end is unused */
				error_exit("close 1");
			if (pfd[1] != STDOUT_FILENO) {
				if (dup2(pfd[1], STDOUT_FILENO) == -1)
					error_exit("dup2 1");
				if (close(pfd[1]) == -1)
					error_exit("close 2");
			} /* Defensive check */
			execlp("ls", "ls", (char *) NULL);
			error_exit("execlp ls"); /* Writes to pipe */
		default:
			break;
	}
	/* Parent falls through to create next child */
	switch (fork()) {
		case -1:
			error_exit("fork");
		case 0:
			/* Second child: exec 'wc' to read from pipe */
			if (close(pfd[1]) == -1)
				/* Write end is unused */
				error_exit("close 3");
			/* Duplicate stdin on read end of pipe; close duplicated descriptor */
			if (pfd[0] != STDIN_FILENO) {
				if (dup2(pfd[0], STDIN_FILENO) == -1)
					error_exit("dup2 2");
				file_fd = open("numberofLines.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);
				printf("filer_fd:  %d\n", file_fd);
				//if(file_fd)
				//	error_exit("open");
				dup2(file_fd, STDOUT_FILENO);
		//			error_exit("dup2 file");
				if (close(pfd[0]) == -1)
					error_exit("close 4");
			} /* Defensive check */
			execlp("wc", "wc", "-l", (char *) NULL);
			error_exit("execlp wc"); /* Reads from pipe */
		default:
			break;
	}
	/* Parent falls through */
	/* Parent closes unused file descriptors for pipe, and waits for children */
	if (close(pfd[0]) == -1)
		error_exit("close 5");
	if (close(pfd[1]) == -1)
		error_exit("close 6");
	if (wait(NULL) == -1)
		error_exit("wait 1");
	if (wait(NULL) == -1)
		error_exit("wait 2");
	exit(EXIT_SUCCESS);
}
