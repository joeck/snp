#include "person.h"

int person_compare(const person_t *a, const person_t *b){
    int result = strncmp(a->name, b->name, NAME_LEN);
    if (result == 0){
	int result = strncmp(a->first_name, b->first_name, NAME_LEN);
	if (result == 0){
	    int result = a->age - b->age;
	}
    }
    return result;
}

