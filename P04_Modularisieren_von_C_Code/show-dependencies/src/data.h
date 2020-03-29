/**
 * @file
 * @brief  Access to the GCC produced dependency data (via gcc -H command line option).
 */

// begin of include guard
// BEGIN-STUDENTS-TO-ADD-CODE
#ifndef DATA_H
#define DATA_H

// END-STUDENTS-TO-ADD-CODE


// includes which are needed in this header file
// BEGIN-STUDENTS-TO-ADD-CODE
#include <stdlib.h>

// END-STUDENTS-TO-ADD-CODE



/**
 * @brief  Directory container for file entries of the dependency file.
 */
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct {   
	const char *name; ///< @brief the path name of the directory as given gcc. 
} dir_t; 

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief  File container for the file entries of the dependency file.
 */
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct {   
	const char *name; ///< @brief  The base name of the file as given by gcc.   
	size_t dir;       ///< @brief  The index of the directory entry.   
	size_t level;     ///< @brief  The level as given by gcc. 
} file_t;

// END-STUDENTS-TO-ADD-CODE



/**
 * @brief  Overall container for all directories and all files from the dependency file.
 */
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct {   
	size_t n_dirs;  ///< @brief  The number of valid entries in the dirs list.   
	dir_t *dirs;    ///< @brief  The list of directories.   
	size_t n_files; ///< @brief  The number of valid entries in the files list.   
	file_t *files;  ///< @brief  The list of files from the dependency file. 
} data_t;

// END-STUDENTS-TO-ADD-CODE



/**
 * @brief            Entry function to read the deendency data from stdin.
 * @param root [IN]  The name of the root file (the deoendency file does not mention the root file, so, it has to be passed from outside).
 * @return           The container of the read data from stdin. See the documentation on gcc -H for details on the dependencies, etc.
 */
// BEGIN-STUDENTS-TO-ADD-CODE
const data_t data_read_all(const char *root);
// END-STUDENTS-TO-ADD-CODE



// end of include guard
// BEGIN-STUDENTS-TO-ADD-CODE
#endif

// END-STUDENTS-TO-ADD-CODE
