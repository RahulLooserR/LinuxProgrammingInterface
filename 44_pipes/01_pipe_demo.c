#include "utilities.h"
#include "pipes.h"

int main()
{
	// two fd is required, pipe_fd[0]-> read
	// pipe_fd[1] -> write
	int pipe_fd[2];
	pid_t pid;
	char buff[BUFFER_SIZE];

	// creating pipe
	check_status(pipe(pipe_fd), "creating  pipe");
	
	// creating child process
	pid = fork();
	check_status(pid, "fork");

	// child process, reads from pipe and closes write end
	if(pid==0){
		close(pipe_fd[1]);
		/*
		while(read(pipe_fd[0], &buff, 1) > 0)
			write(stdout, &buff, 1);
		*/
		printf("child reading\n");
		check_status(read(pipe_fd[0], buff, BUFFER_SIZE), "child read");
		printf("Read by child: %s\n", buff);
		close(pipe_fd[0]);
		exit(EXIT_SUCCESS);
	}

	// parent process, write to the pipe and closes read end
	else{
		close(pipe_fd[0]);
		printf("Parent: Enter ->\n");
		fgets(buff, BUFFER_SIZE, stdin);
		check_status(write(pipe_fd[1], buff, BUFFER_SIZE), "parent write");
		close(pipe_fd[1]);
		wait(NULL);
	}
	
	return 0;
}
