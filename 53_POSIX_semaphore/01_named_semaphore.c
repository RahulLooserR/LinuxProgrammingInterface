/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 01_named_semaphore.c
 * Created on    : Wednesday 14 October 2020 08:08:13 AM IST
 * Last modified : Wednesday 14 October 2020 02:44:47 PM IST
 * Description   : 
 * ***********************************************************************/


#include "semaphores.h"
#include "utilities.h"

static void usageError(const char *progName)
{
	fprintf(stderr, "Usage: %s [-cx] name [octal-perms [value]]\n", progName);
	fprintf(stderr, "  -c  Create semaphore (O_CREAT)\n");
	fprintf(stderr, "  -x  Create exclusively (O_EXCL)\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	int flags, opt;
	mode_t perms;
	unsigned int value;
	sem_t *sem;

	// parsing command line arguments
	flags = 0;
	while ((opt = getopt(argc, argv, "cx")) != -1){
		switch (opt){
			case 'c': flags |= O_CREAT; break;
			case 'x': flags |= O_EXCL; break;
			default: usageError(argv[0]);
		}
	}

	// optind -> index for next element
	printf("optind: %d\n", optind);
	if (optind > argc || argc <= 1)
		usageError(argv[0]);

	printf("argv[optind]: %s\n", argv[optind]);
	sem = sem_open(argv[optind], flags);
	if (sem == SEM_FAILED){
		error_exit("sem open");
	}

	exit(EXIT_SUCCESS);

	return  0;
}
