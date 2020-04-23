#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_insert(node_t *anchor, const person_t *person){
    node_t *curr_anchor = anchor;
    while (anchor != curr_anchor->next){
        int compare = person_compare(person, &curr_anchor->next->content);
        if (compare = 0 || compare < 0){
            break;
        }
        curr_anchor = curr_anchor->next;
    }
    node_t *new_next = malloc(sizeof(node_t));
    new_next->content = *person;
    new_next->next = curr_anchor->next;
    curr_anchor->next = &new_next;
}

void list_remove(node_t *anchor, const person_t *person){
    int compare = person_compare(&anchor->next->content, person);

    if(compare > 0){
        list_remove(anchor->next, person);
    } else if (compare < 0){
        return;
    } else {
        node_t *new_next = anchor->next->next;
        free (anchor->next);
        anchor->next = new_next;
    }
}

void list_clear(node_t *anchor){
    if (anchor->next != NULL){
        node_t *new_anchor = anchor->next;
        anchor->next = NULL;
        list_clear(new_anchor);
    }
    free(anchor);
    anchor = malloc(sizeof(node_t));
    *(anchor) = (node_t) {(person_t) {"", "", 0}, anchor};
}

void list_show(node_t *anchor){
    node_t *next_anchor = anchor->next;
    while(anchor != next_anchor){
        printf("\n---------------");
        printf("\nName: '%s'", next_anchor->content.name);
        printf("\nFirst Name: '%s'", next_anchor->content.first_name);
        printf("\nAge: '%s'", next_anchor->content.age);
        printf("\n---------------");
        next_anchor = next_anchor->next;
    }
}
