#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

//srand(time(NULL));

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
    if (strcmp(s1 -> artist, s2 -> artist) != 0) {
        return strcmp(s1 -> artist, s2 -> artist);
    } return strcmp(s1 -> name, s2 -> name);
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
    struct song_node * new = create(a, n);
    if (temp == NULL) {
        return new;
    }

    // error may occur here
    if (compare(temp, new) > 0) {
        new -> next = temp;
        return new;
    } //

    while (compare(temp -> next, new) < 0 && temp -> next != NULL) {
        temp = temp -> next;
    }
    // insert new node to the iterating node's next node since that
    // was how the while loop exited, and where compare == 0
    new -> next = temp -> next;
    temp -> next = new; // connect both sides of the node
    return node; // returns the original head node
}

// struct song_node * find_song(struct song_node * head, struct song_node * target) {
    // struct song_node * temp = head;
    // int comp = compare(temp, head);
    // if (comp == 0) {
        // return temp -> artist;
    // } else if (temp -> next == NULL || comp > 0) {
        // return ULL;
    // } else {
        // return find_song(temp -> next, target);
    // }
// }

struct song_node * find_song(struct song_node * song, char * artist, char * name) {
    struct song_node * temp = find_artist(song, artist);
    int comp = strcmp(song -> name, name);
	int comp2 = strcmp(song -> artist, artist);
    if (comp == 0) {
        return temp;
    } else if (temp -> next == NULL || comp > 0 || comp2 > 0) {
        return NULL;
    } else {
        return find_song(temp -> next, artist, name);
    }
}

struct song_node * find_artist(struct song_node * song, char * artist) {
    struct song_node * temp = song;
    int comp = strcmp(song -> artist, artist);
    if (comp == 0) {
        return temp;
    } else if (temp -> next == NULL || comp > 0) {
        return NULL;
    } else {
        return find_artist(temp -> next, artist);
    }
}

struct song_node * rand_point(struct song_node * song) {
	struct song_node * temp = song;
	srand(time(NULL)); //not sure if this should be here or in main
	while (rand() % 2){
		if (temp -> next == NULL)
			return temp;
		else
			temp = temp->next;
	}
	return temp;
}

struct song_node * remove_song(struct song_node * head, struct song_node * song) {
    if (compare(head, song) == 0) {
        struct song_node * ret = head -> next;
        free(head);
        return ret;
    }
    struct song_node * prev;
    struct song_node * temp = head;
    while(compare(temp -> next, song) <= 0 && temp -> next != NULL) {
        prev = temp;
        temp = temp -> next;
    } if (temp -> next == NULL) {
        prev -> next = NULL;
        free(temp);
        return head;
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
