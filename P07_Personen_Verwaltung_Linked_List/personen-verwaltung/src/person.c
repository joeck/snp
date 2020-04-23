#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int person_compare(const person_t *a, const person_t *b){
    signed int result = strncmp(a->name, b->name, NAME_LEN);
    if (result == 0){
        result = strncmp(a->first_name, b->first_name, NAME_LEN);
        if (result == 0){
            result = a->age - b->age;
        }
    }
    return result;
}

