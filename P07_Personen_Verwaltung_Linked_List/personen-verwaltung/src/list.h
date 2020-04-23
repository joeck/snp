#ifndef _LIST_H_
#define _LIST_H_
#include "person.h"

typedef struct node {
    person_t content;
    struct node *next;
} node_t;

void list_insert(node_t *anchor, const person_t *person);

void list_remove(node_t *anchor, const person_t *person);

void list_clear(node_t *anchor);

void list_show(node_t *anchor);

#endif //_LIST_H_
