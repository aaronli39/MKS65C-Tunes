#include <stdio.h>
#include "linked_list.h"
#include "library.h"

int main() {
  printf("SICK MUSIC PLAYER by Aaron Li and Camilla Cheng\n\n");
  printf("LINKED LIST TESTING\n");
  printf("=================================================\n\n");
  struct song_node start = create("the beatles", "hey jude");
  start = insert_front(start, "katy perry", "firework");
  start = insert_order(start, "maroon 5", "she will be loved")

  printf("Testing print_list\n ");
  print_list(start);
  printf("=================================================\n\n");

  printf("Testing find_song\n");
  struct song_node find_s0 = find_song("maroon 5", "she will be loved");
  printf("looking for [maroon 5 : she will be loved]\n");
  if (find_s0 != NULL) {
    printf(" song found! [%s]\n", find_s0->name);
  }
  else {printf(" song not found :(\n")};

  struct song_node find_s1 = find_song("not artist", "not name");
  printf("looking for [not artist : not name]\n");
  if (find_s1 != NULL) {
    printf(" song found! [%s]\n", find_s1->name);
  }
  else {printf(" song not found :(\n")};
  printf("=================================================\n\n");

  printf("Testing find_artist\n");
  struct song_node find_a0 = find_artist("maroon 5");
  printf("looking for [maroon 5 : she will be loved]\n");
  if (find_a0 != NULL) {
    printf(" song found! [%s]\n", find_a0->name);
  }
  else {printf(" song not found :(\n")};

  struct song_node find_a1 = find_song("not artist", "not name");
  printf("looking for [not artist : not name]\n");
  if (find_a1 != NULL) {
    printf(" song found! [%s]\n", find_a1->name);
  }
  else {printf(" song not found :(\n")};
  printf("=================================================\n\n");
  printf("=================================================\n\n");
  printf("=================================================\n\n");
  printf("=================================================\n\n");

}
