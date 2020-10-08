/*
 * redirection is simulation is  done for 
 * ls -la > file.txt 
 * done by using fork(), exec(), dup()/dup2()
 */

#include "pipes.h"
#include "utilities.h"

int main()
{
	int oldfd = STDOUT_FILENO; // extern FILE *stdin;
	pid_t pid;
	int newfd;
	//	char *command[] = {"ls", "-la"};

	pid = fork();
	check_status(pid, "fork");

	// child process
	if(pid == 0){
		newfd = open("file.txt", O_CREAT | O_TRUNC | O_WRONLY);

		check_status(dup2(newfd, oldfd), "dup call");
		//check_status(execvp(command[0], command), "exec system call");
		check_status(execl("/bin/ls", "-la", NULL), "exec system call");
		
		//nothing works here after
		printf("its written to file\n");
		check_status(dup2(oldfd, newfd), "dup call in child");
		printf("its written to stdout\n");
		close(newfd);
	}

	else{
		wait(NULL);
		printf("successfuly executed ls command, check for file.txt\n");
	}


	return 0;
}
