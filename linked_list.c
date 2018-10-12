#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// prints the linked list of the specified node element
void print_list(struct node * node) {
    struct node * temp = node;
    if(! temp) {
        printf("[]\n");
    } else {
        if(temp -> next == NULL) {
            printf("[%d] -> [NULL]\n", temp -> i);
            return;
        } else {
            printf("[%d] -> ", temp -> i);
            return(print_list(temp -> next));
        }
    }
}

// creates and returns a pointer with a value of the input
struct node * create(int i) {
    struct node * temp;
    temp = malloc(sizeof(struct node));
    temp -> i = i;
    temp -> next = NULL;
    return temp;
}

// insert to the front of input node a new node with value x.
// return the new linked list
struct node * insert_front(struct node * node, int x) {
    struct node * temp = node;
    if(temp -> next == NULL) {
        temp -> next = create(x);
        return temp;
    } else {
        return(insert_front(temp -> next, x));
    }
}

// free the linked list of the given node
struct node * free_list(struct node * node) {
    if (node -> next == NULL) {
        free(node);
    } else {
        free_list(node -> next);
        free(node);
    }
}
