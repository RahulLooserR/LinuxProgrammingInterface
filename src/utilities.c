/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : utilities.c
 * Created on    : Saturday 04 January 2020 07:48:29 PM IST
 * Last modified : Saturday 04 January 2020 11:00:20 PM IST
 * Description   : 
 * ***********************************************************************/

#include "utilities.h"

void error_exit(char *msg)
{
	perror(msg);
	exit(1);
}
