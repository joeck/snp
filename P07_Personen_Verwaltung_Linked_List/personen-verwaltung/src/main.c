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
#include "list.c"

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
	list_clear(anchor);

	char input = ' ';
	while (input != 'E'){
		printf("\nI(nsert), R(emove), S(how), C(lear), E(nd): ");
		scanf("%c", input);

		switch (input){
			case 'i':
			case 'I':
				printf("\nName: ");
				person_t *new_person = malloc(sizeof(person_t));
				if (new_person = NULL){
					printf("\nCouldn't allocate memory. List is too big!");
					break;
				}
				scanf("%20s", new_person->name);
				printf("\nFirst name: ");
				scanf("%20s", new_person->first_name);
				printf("\nAge: ");
				scanf("%u", new_person->age);
				printf("adding new Person(Name:'%s',Firstname:'%s',Age:%u)",new_person->name,new_person->first_name,new_person->age);
				list_insert(anchor, new_person);
				break;
			
			case 'r':
			case 'R':
				person_t *remove_person = malloc(sizeof(person_t));
				if (remove_person = NULL){
					printf("\nCouldn't allocate memory. List is too big!");
					break;
				}
				scanf(" %20s",remove_person->name);
				printf("First Name: ");
				scanf(" %20s",remove_person->first_name);
				printf("Age: ");
				scanf(" %u",&remove_person->age);
				printf("removing Person(Name:'%s',Firstname:'%s',Age:%u)",remove_person->name,remove_person->first_name,remove_person->age);
				list_remove(anchor,remove_person);
				break;

			case 's':
			case 'S':
				list_show(anchor);
				break;

			case 'c':
			case 'C':
				int result = list_clear(anchor);
				if (result = 1){
					return EXIT_FAILURE;
				}
				break;

			case 'e':
			case 'E':
				printf("Goodbye!");
				break;

			default:
				break;
		}
	}
	
	list_clear(anchor);
    
	// END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}
