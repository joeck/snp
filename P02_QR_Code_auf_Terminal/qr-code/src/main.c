/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab P02 QR Code
 * @remark prerequisite: sudo apt install qrencode
 */
#include <stdio.h>
#include <stdlib.h>

// define local macros
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   main function
 * @returns always success (0)
 */
int main()
{
	// BEGIN-STUDENTS-TO-ADD-CODE

	FILE *file;
	file = stdin;

	int c;
	printf("\033[0m\n");
	while ((c = getc(file)) != EOF){
		if (c == '\n'){
			printf("\033[0m\n");
		} else if (c == ' ') {
			printf("\033[47m ");
		} else {
			printf("\033[40m ");
		}
	}
	printf("\033[0m\n");
	fclose(file);
	// END-STUDENTS-TO-ADD-CODE
	return EXIT_SUCCESS;
}
