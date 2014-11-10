/*
	CTurt's implementation of exceptions in C
	licensed under the MIT License (MIT)
	
	https://github.com/CTurt/Exception
*/

/*
	Program output:

	Doing something...
	Process failed due to error 1!
	End of program
*/

#include <stdio.h>

#include "exception.h"

void process(void) {
	printf("Doing something...\n");
	throw(1);
}

int main(void) {
	// Create a new exception
	exception(
		try() {
			process();
			
			// this never happens because process always throws error 1
			printf("Got to end of process!\n");
		}
		
		// is executed when throw(1) is called within the try
		catch(1) {
			printf("Process failed due to error 1!\n");
		}
		
		// is executed when a throw is called within the try and there
		// is no catch specific to the exception
		finally() {
			// use e to get the value passed to throw
			printf("Process failed due to error %d!\n", e);
		}
	);
	
	printf("End of program\n");
	
	return 0;
}
