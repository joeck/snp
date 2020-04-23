#ifndef _PERSON_H_
#define _PERSON_H_

#define NAME_LEN 20 

typedef struct{
    char    name[NAME_LEN];
    char    first_name[NAME_LEN];
    unsigned int age;
} person_t;

int person_compare(const person_t *a, const person_t *b);


#endif //_PERSON_H_
