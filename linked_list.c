#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

// prints the linked list of the specified node element
void print_list(struct song_node * node) {
  struct song_node * temp = node;
  if(! temp) {
    printf("[]\n");
  } else {
    if(temp -> next == NULL) {
      printf("[%s, %s] -> [NULL]\n", temp -> artist, temp -> name);
      return;
    } else {
      printf("[%s, %s] -> ", temp -> artist, temp -> name);
      return(print_list(temp -> next));
    }
  }
}

// creates and returns a pointer with a value of the input
struct song_node * create(char * a, char * n) {
  struct song_node * temp;
  temp = malloc(sizeof(struct song_node));
  strcpy(temp -> artist, a);
  strcpy(temp -> name, n);
  temp -> next = NULL;
  return temp;
}

// insert to the front of input node a new node with value x.
// return the new linked list
struct song_node * insert_front(struct song_node * node, char * a, char * n) {
  struct song_node * temp = node;
  if(temp -> next == NULL) {
    temp -> next = create(a, n);
    return temp;
  } else {
    return(insert_front(temp -> next, a, n));
  }
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

// free the linked list of the given node
struct song_node * free_list(struct song_node * node) {
  if (node -> next == NULL) {
    free(node);
  } else {
    free_list(node -> next);
    free(node);
  }
}

//test
int main() {
  struct song_node * x;
  strcpy(x->name, "abc");
  strcpy(x->artist, "camilla");
  x->next = NULL;

  x = insert_order(x, "camilla", "abd");

  print_list(x);

  return 0;


}
