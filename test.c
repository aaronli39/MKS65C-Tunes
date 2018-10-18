#include <stdio.h>
#include "linked_list.h"
#include "library.h"

int main() {
  printf("SICK MUSIC PLAYER by Aaron Li and Camilla Cheng\n\n");
  printf("LINKED LIST TESTING\n");
  printf("=================================================\n\n");
  struct song_node * s0 = make("the beatles", "hey jude");
  struct song_node * s1 = make("the beatles", "hey jude");
  struct song_node * s2 = make("katy perry", "firework");
  struct song_node * s3 = make("maroon 5", "she will be loved");
  struct song_node * s4 = make("neon trees", "animal");
  struct song_node * s5 = make("neon trees", "everybody talks");
  struct song_node * s6 = make("imagine dragons", "warriors");
  struct song_node * s7 = make("mindy gledhill", "anchor");
  struct song_node * s8 = make("of monsters and men", "little talks");
  struct song_node * s9 = make("fall out boy", "immortals");
  
  struct song_node * start;
  
  //Testing insert_front
  start = insert_front(start, s0->artist, s0->name);
  printf("Testing print_song\n ");
  print_song(start);
  printf("\n");
  
  //Testing insert_order
  start = insert_order(start, s1);
  print_song(start);
  start = insert_order(start, s2);
  print_song(start);
  start = insert_order(start, s3);
  print_song(start);
  start = insert_order(start, s4);
  print_song(start);
  start = insert_order(start, s5);
  print_song(start);
  start = insert_order(start, s6);
  print_song(start);
  start = insert_order(start, s7);
  print_song(start);
  start = insert_order(start, s8);
  print_song(start);
  start = insert_order(start, s9);
  print_song(start);
  printf("=================================================\n\n");
  
  printf("Testing print_songs\n ");
  print_songs(start);
  printf("\n");
  printf("=================================================\n\n");

  printf("Testing find_node\n");
  struct song_node * find_s0 = find_node(start, s6);
  printf("looking for [%s: %s]\n", s6->artist, s6->name);
  if (find_s0 != NULL) {
    printf(" song found! ('w') ");
    print_song(find_s0);
    printf("\n");
  }
  else
    printf(" song not found ('m')\n");

  struct song_node * not_song = make("camilla cheng", "i love cs");
  struct song_node * find_s1 = find_node(start, not_song);
  printf("looking for [%s, %s]\n", not_song->artist, not_song->name);
  if (find_s1 != NULL) {
    printf(" song found! ('w') ");
    print_song(find_s1);
    printf("\n");
  }
  else
    printf(" song not found ('m')\n");
  printf("=================================================\n\n");

  printf("Testing find_artist\n");
  struct song_node * find_a0 = find_artist(start, s3->artist);
  printf("looking for [%s: %s]\n", s3->artist, s3->name);
  if (find_a0 != NULL) {
    printf(" artist found! ('O')");
    print_songs(find_a0);
    printf("\n");
  }
  else
    printf(" artist not found (>_<)\n");

  struct song_node * not_artist = make("aaron li", "i love mr. k <3");
  struct song_node * find_a1 = find_artist(start, not_artist->artist);
  printf("looking for [%s: %s]\n", not_artist->artist, not_artist->name);
  if (find_a1 != NULL) {
    printf(" song found! ('O')");
    print_songs(find_a1);
    printf("\n");
  }
  else
    printf(" song not found (>_<)\n");
  printf("=================================================\n\n");

  printf("Testing rand_point");

  printf("=================================================\n\n");
  printf("=================================================\n\n");
  printf("=================================================\n\n");

}
