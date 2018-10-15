#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"



// prints the linked list of the specified node element
void print_list(struct song_node * node) {
    struct song_node * temp = node;
    if(temp == NULL) {
        return;
    } else {
        if(temp -> next == NULL) {
            printf("%s: %s | ", temp -> artist, temp -> name);
            return;
        } else {
            printf("%s: %s | ", temp -> artist, temp -> name);
            return(print_list(temp -> next));
        }
    }
}

// creates and returns a pointer to a new song node
struct song_node * create(char * artist, char * name) {
    struct song_node * temp;
    temp = malloc(sizeof(struct song_node));
    strcpy(temp -> artist, artist);
    strcpy(temp -> name, name);
    temp -> next = NULL;
    return temp;
}

// compares two songs alphabetically first by artist then by name
int compare(struct song_node * s1, struct song_node * s2) {
    if (strcmp(s1 -> artist, s2 -> artist) < 0) {
        return -1;
    } else if (strcmp(s1 -> artist, s2 -> artist) > 0) {
        return 1;
    } else if (strcmp(s1 -> name, s2 -> name) < 0) {
        return -1;
    } else if (strcmp(s1 -> name, s2 -> name) > 0) {
        return 1;
    } return 0;
}

// insert to the front of input node a new node with value x.
// return the new linked list
struct song_node * insert_front(struct song_node * node, char * a, char * n) {
    struct song_node * output = create(a, n);
    output -> next = node;
    return output;
}

struct song_node * insert_order(struct song_node * node, char * a, char * n) {
    struct song_node * temp = node;
    // right now, this only tests for the first letter
    // will need to write a new function to check the entire word
    if (strcmp(a, temp -> artist) <= 0) {
        return insert_name(node, a, n);
    }
    else {
        return insert_order(node -> next, a, n);
    }
}

//helper func for insert_order
struct song_node * insert_name(struct song_node * node, char * a, char * n) {
    struct song_node * temp = node;
    // right now, this only tests for the first letter
    // will need to write a new function to check the entire word
    if (strcmp(n, temp->name) <= 0) {
        return insert_front(node, a, n);
    }
    else {
        return insert_name(node -> next, a, n);
    }
}

struct song_node * find_song(struct song_node * head, struct song_node * target) {
    struct song_node * temp = head;
    int comp = compare(temp, head);
    if (temp -> next == NULL || comp > 0) {
        return NULL;
    } else {
        
    }

}
// free the linked list of the given node
struct song_node * free_list(struct song_node * node) {
    if (node -> next == NULL) {
        free(node);
    } else {
        free_list(node -> next);
        free(node);
    }
}
