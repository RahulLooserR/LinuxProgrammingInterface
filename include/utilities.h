/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : utilities.h
 * Created on    : Saturday 04 January 2020 07:46:44 PM IST
 * Last modified : Saturday 04 January 2020 07:51:19 PM IST
 * Description   : 
 * ***********************************************************************/

#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 256

void error_exit(char *msg);
void check_status(int result, const char*msg);

#endif
