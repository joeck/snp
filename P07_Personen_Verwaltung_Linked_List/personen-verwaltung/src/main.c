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
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "person.h"

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(int argc, char* argv[])
{
	// BEGIN-STUDENTS-TO-ADD-CODE

	node_t *anchor = malloc(sizeof(node_t));
	*(anchor) = (node_t) {(person_t) {"", "", 0}, anchor};

	char input = '*';
	while (input != 'E'){
		printf("\nI(nsert), R(emove), S(how), C(lear), E(nd): ");
		scanf(" %c", &input);

		switch (input){
			case 'i':
			case 'I':
				printf("---Insert---");
				person_t *new_person = malloc(sizeof(person_t));
				if (!new_person){
					printf("Couldn't allocate memory. List is too big!\n");
					break;
				}
				printf("\nName: ");
				scanf("%20s", new_person->name);
				printf("First name: ");
				scanf("%20s", new_person->first_name);
				printf("Age: ");
				scanf("%u", &new_person->age);
				list_insert(anchor, new_person);
				printf("------\n");
				break;
			
			case 'r':
			case 'R':
				printf("---Delete---");
				printf("\nName: ");
				person_t *remove_person = malloc(sizeof(person_t));
				if (!remove_person){
					printf("Couldn't allocate memory. List is too big!\n");
					break;
				}
				scanf("%20s",remove_person->name);
				printf("First Name: ");
				scanf("%20s",remove_person->first_name);
				printf("Age: ");
				scanf("%u",&remove_person->age);
				list_remove(anchor,remove_person);
				printf("------\n");
				break;

			case 's':
			case 'S':
				printf("---Show---\n");
				list_show(anchor);
				break;

			case 'c':
			case 'C':
				printf("---Clear---\n");
				list_clear(anchor);
				break;

			case 'e':
			case 'E':
				printf("Goodbye!\n");
				input = 'E';
				list_clear(anchor);
				break;

			default:
				printf("No action is mapped to this key...\n");
				break;
		}
	}
    
	// END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}
