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
 * @brief Lab P02 bit Manipulation
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define USAGE "usage: %s value [bitnr]\n value in the range 0..255\n bitnr in the range 0..7\n"

/**
 * @brief   main function
 * @returns always success (0)
 */
int main(int argc, const char* argv[])
{
	// check arguments and get the values
	// BEGIN-STUDENTS-TO-ADD-CODE
	uint8_t u_int;
	int8_t s_int;

	if (argc == 1){
		//no argument provided
		printf("no argument passed\n");
		return EXIT_FAILURE;
	}
	if (atoi(argv[1]) < 0 || atoi(argv[1]) > 255){
		printf("not a valid argument\n");
		return EXIT_FAILURE;
	}

	// END-STUDENTS-TO-ADD-CODE
	
	u_int = atoi(argv[1]);
	if (argc == 2) { //only one argument
		// BEGIN-STUDENTS-TO-ADD-CODE
		s_int = atoi(argv[1]);
		const uint8_t overflow = u_int + 255;
		
		printf("unsigned:%5d (0x0%x)\n", u_int, u_int);
		printf("  signed:%5d (0x0%x)\n", s_int, s_int);
		printf("    +255:%5d (0x0%x)\n", overflow, overflow);
		printf("   one's:%5d (0x%x)\n", ~u_int, ~u_int);
		printf("   two's:%5d (0x%x)\n", (~u_int)+1, (~u_int)+1);

		// END-STUDENTS-TO-ADD-CODE
	} else {
		// BEGIN-STUDENTS-TO-ADD-CODE

		int second = atoi(argv[2]);
		if(second < 0 || second > 7){
			printf("not a valid second argument\n");
			return EXIT_FAILURE;
		}
		printf("%18s%6s%6s\n", "dec", "hex", "oct");
		printf("%-13s:%4d  0x%02x  %04o\n", "your input", u_int, u_int, u_int);
		char* message = "not set.";
		int bit_o = 00000001 << second;
		if (bit_o & u_int){message = "set.";} //AND
		printf("bit %d is %s\n", second, message);
		uint8_t u_int_c = ~bit_o & u_int; //inverted AND
		printf("bit %d cleared:%4d  0x%02x  %04o\n", second, u_int_c, u_int_c, u_int_c);
		uint8_t u_int_s = bit_o | u_int; //OR
		printf("bit %d set    :%4d  0x%02x  %04o\n", second, u_int_s, u_int_s, u_int_s);
		uint8_t u_int_f = bit_o ^ u_int; //XOR
		printf("bit %d flipped:%4d  0x%02x  %04o\n", second, u_int_f, u_int_f, u_int_f);


		// END-STUDENTS-TO-ADD-CODE
	}
	
	return EXIT_SUCCESS;
}
