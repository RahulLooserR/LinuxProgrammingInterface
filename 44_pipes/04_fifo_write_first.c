/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 04_fifo.c
 * Created on    : Monday 12 October 2020 03:35:25 PM IST
 * Last modified : Monday 12 October 2020 03:38:56 PM IST
 * Description   : 
 * ***********************************************************************/

#include "utilities.h"
#include "pipes.h"

int main()
{
	int fd; 
  
    // FIFO file path 
    char * myfifo = "/tmp/myfifo"; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
    mkfifo(myfifo, 0666); 
  
    char arr1[80], arr2[80]; 
    while (1) 
    { 
        // Open FIFO for write only 
        fd = open(myfifo, O_WRONLY); 
  
        // Take an input arr2ing from user. 
        // 80 is maximum length 
        fgets(arr2, 80, stdin); 
  
        // Write the input arr2ing on FIFO 
        // and close it 
        write(fd, arr2, strlen(arr2)+1); 
        close(fd); 
  
        // Open FIFO for Read only 
        fd = open(myfifo, O_RDONLY); 
  
        // Read from FIFO 
        read(fd, arr1, sizeof(arr1)); 
  
        // Print the read message 
        printf("User2: %s\n", arr1); 
        close(fd); 
    } 
	return 0;
}
