/**
 * @file
 * @brief  Provides output functions for various file formats.
 * @param data [IN] Container of the dependency data.
 */
// define proper header file here, with include gaurd, etc.
// BEGIN-STUDENTS-TO-ADD-CODE
#ifndef OUTPUT_H
#define OUTPUT_H
#include <stdlib.h>
#include "data.h" 
/**
 * @breif	 	Produces DOT output of the dependencies given in data.
 * @param data [IN]	Container of the dependency data.
 */
void output_dot(const data_t data);



#endif
// END-STUDENTS-TO-ADD-CODE
