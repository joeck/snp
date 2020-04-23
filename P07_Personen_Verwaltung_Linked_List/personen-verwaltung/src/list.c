#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_insert(node_t *anchor, const person_t *person){
    node_t *curr_anchor = anchor;
    while (anchor != curr_anchor->next){
        int compare = person_compare(person, &curr_anchor->next->content);
        if ((compare < 0)){
            break;
        } else if ((compare = 0)){
            printf("\nPerson already exists");
            return;
        }
        curr_anchor = curr_anchor->next;
    }
    node_t *new_next = malloc(sizeof(node_t));
    new_next->content = *person;
    new_next->next = curr_anchor->next;
    curr_anchor->next = new_next;
}

void list_remove(node_t *anchor, const person_t *person){
    int compare = person_compare(person, &anchor->next->content);

    if(compare < 0){
        list_remove(anchor->next, person);
    } else if ((compare > 0)){
        printf("\nThat person doesn't exist, please check your spelling.");
        return;
    } else if ((compare = 0)) {
        node_t *new_next = anchor->next->next;
        free (anchor->next);
        anchor->next = new_next;
    } else {
        printf("\nWe ran into an unexpected error. Sorry");
    }
}

void list_clear(node_t *anchor){
    if (anchor->next != NULL){
        node_t *new_anchor = anchor->next;
        anchor->next = NULL;
        list_clear(new_anchor);
    }
    free(anchor);

    //create new anchor of linked list
    anchor = malloc(sizeof(node_t));
    if ((anchor = NULL)){
        printf("We couldn't allocate any memory.");
    }
    *(anchor) = (node_t) {(person_t) {"", "", 0}, anchor};
}

void list_show(node_t *anchor){
    node_t *next_anchor = anchor->next;
    while(anchor != next_anchor){
        printf("\n---------------");
        printf("\nName: '%s'", next_anchor->content.name);
        printf("\nFirst Name: '%s'", next_anchor->content.first_name);
        printf("\nAge: '%d'", next_anchor->content.age);
        printf("\n---------------");
        next_anchor = next_anchor->next;
    }
}
