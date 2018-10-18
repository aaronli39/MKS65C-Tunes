#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linked_list.h"
#include "library.h"

int main() {

  srand(time(NULL));
  
  printf("***SICK MUSIC PLAYER by Aaron Li and Camilla Cheng***\n");
  printf("LINKED LIST TESTING\n");
  printf("=================================================\n\n");
  
  struct song_node * s0 = make("The Beatles", "Hey Jude");
  struct song_node * s1 = make("Plain White T's", "Hey There Delilah");
  struct song_node * s2 = make("Katy Perry", "Firework");
  struct song_node * s3 = make("Maroon 5", "She Will Be Loved");
  struct song_node * s4 = make("Neon Trees", "Animal");
  struct song_node * s5 = make("Neon Trees", "Everybody Talks");
  struct song_node * s6 = make("Imagine Dragons", "Warriors");
  struct song_node * s7 = make("Mindy Gledhill", "Anchor");
  struct song_node * s8 = make("Of Monsters and Men", "Little Talks");
  struct song_node * s9 = make("Fall Out Boy", "Immortals");
  
  struct song_node * start = NULL;
  
  printf("=== Insert in Front ===\n");
  start = insert_front(start, s0->artist, s0->name);
  printf("--- TESTING print_song ---\n ");
  print_song(start);
  printf("\n");

  printf("=== Inserting in Alphabetical Order ===\n");
  start = insert_order(start, s1);
  //print_songs(start);
  start = insert_order(start, s2);
  //print_songs(start);
  start = insert_order(start, s3);
  //print_songs(start);
  start = insert_order(start, s4);
  //print_songs(start);
  start = insert_order(start, s5);
  //print_songs(start);
  start = insert_order(start, s6);
  //print_songs(start);
  start = insert_order(start, s7);
  //print_songs(start);
  start = insert_order(start, s8);
  //print_songs(start);
  start = insert_order(start, s9);
 
  printf("--- TESTING print_songs ---\n ");
  print_songs(start);
  printf("=================================================\n\n");
  
  printf("--- TESTING compare (HELPER FUNCTION) ---\n");
  int c;
  
  c = compare(s6, s6);
  printf("Comparing [%s: %s] to [%s: %s] \n\t%d\n", s6->artist, s6->name, s6->artist, s6->name, c);
  c = compare(s7, s6);
  printf("Comparing [%s: %s] to [%s: %s] \n\t%d\n", s7->artist, s7->name, s6->artist, s6->name, c);
  c = compare(s8, s9);
  printf("Comparing [%s: %s] to [%s: %s] \n\t%d\n", s8->artist, s8->name, s9->artist, s9->name, c);
  c = compare(s1, s5);
  printf("Comparing [%s: %s] to [%s: %s] \n\t%d\n", s1->artist, s1->name, s5->artist, s5->name, c);
  c = compare(s4, s5);
  printf("Comparing [%s: %s] to [%s: %s] \n\t%d\n", s4->artist, s4->name, s5->artist, s5->name, c);
  
  printf("=================================================\n\n");

  printf("--- TESTING find_node--- \n\n");
  struct song_node * find_s0 = find_node(start, s6);
  printf(" looking for [%s: %s]\n", s6->artist, s6->name);
  if (find_s0 == NULL) 
	  printf("  song not found ('A')\n");
  else {
    printf("  song found! ('w') ");
    print_song(find_s0);
  }

  struct song_node * not_song = make("camilla cheng", "i love cs");
  struct song_node * find_s1 = find_node(start, not_song);
  printf(" looking for [%s, %s]\n", not_song->artist, not_song->name);
  if (find_s1 == NULL) 
	printf("  song not found ('A')\n");
  else {
    printf("  song found! ('w') ");
    print_song(find_s1);
  }
  
  printf("=================================================\n\n");

  printf("--- TESTING find_artist ---\n\n");
  struct song_node * find_a0 = find_artist(start, s3->artist);
  printf(" looking for [%s: %s]\n", s3->artist, s3->name);
  if (find_a0 == NULL) 
	printf("  artist not found (>_<)\n");
  else {
    printf("  artist found! ('O') ");
    print_songs(find_a0);
  }

  struct song_node * not_artist = make("aaron li", "i love mr. k <3");
  struct song_node * find_a1 = find_artist(start, not_artist->artist);
  printf(" looking for [%s: %s]\n", not_artist->artist, not_artist->name);
  if (find_a1 == NULL) 
	printf("  song not found (>_<)\n");
  else {
    printf("  song found! ('O') ");
    print_songs(find_a1);
  }
  printf("=================================================\n\n");

  printf("--- TESTING rand_point ---\n\n");
  print_song(random_song(start));
  print_song(random_song(start));
  print_song(random_song(start));
  printf("=================================================\n\n");

  printf("--- TESTING remove ---\n\n");
  printf("Removing [%s: %s]\n ", s4->artist, s4->name);
  start = remove_song(start, s4);
  print_songs(start);
  printf("Removing [%s: %s]\n ", s7->artist, s7->name);
  start = remove_song(start, s7);
  print_songs(start);
  printf("=================================================\n\n");
  
  printf("--- TESTING free_list ---\n\n");
  free_list(start);
  
  printf("=================================================\n\n");
  printf("MUSIC LIBRARY TESTS\n\n");
  printf("=================================================\n\n");
  
  s0 = make("My Chemical Romance", "Teenagers");
  s1 = make("Troye Sivan", "Youth");
  s2 = make("Panic at the Disco!", "House of Memories");
  s3 = make("Oliver Riot", "Alcatraz");
  s4 = make("Aston Merrygold", "Get Stupid");
  s5 = make("Billie Eilish", "My Boy");
  s6 = make("Ansel Elgort", "Thief");
  s7 = make("Mindy Gledhill", "Anchor");
  s8 = make("Drax Project", "Woke Up Late");
  s9 = make("Drax Project", "Toto");
 
  struct library * lib = create_lib();
  printf("=== Adding Songs to Lib ===\n");
  
  lib = add_song(lib, s0);
  lib = add_song(lib, s1);
  lib = add_song(lib, s2);
  lib = add_song(lib, s3);
  lib = add_song(lib, s4);
  lib = add_song(lib, s5);
  lib = add_song(lib, s6);
  lib = add_song(lib, s7);
  lib = add_song(lib, s8);
  lib = add_song(lib, s9);
  
  printf("--- TESTING print_library ---\n\n");
  print_lib(lib);
  
  printf("=================================================\n\n");
  
  printf("--- TESTING print_by_letter ---\n\n");
  print_by_letter(lib, 'A');
  print_by_letter(lib, 'T');
  print_by_letter(lib, 'J');
  print_by_letter(lib, '?');
  
  printf("=================================================\n\n");
  
  printf("--- TESTING print_by_artist ---\n\n");
  print_by_artist(lib, "Oliver Riot");
  printf("\n\n");
  print_by_artist(lib, "Drax Project");
  printf("\n\n");
  print_by_artist(lib, "Camilla Cheng");
  
  printf("=================================================\n\n");
  
  printf("--- TESTING search_song ---\n\n");
  find_s0 = search_song(lib, s3->name, s3->artist);
  printf(" looking for [%s: %s]\n", s3->artist, s3->name);
  if (find_s0 == NULL) 
	printf("  song not found (O_O)\n");
  else {
    printf("  song found! ('U') ");
    print_songs(find_s0);
  }
  find_s1 = search_song(lib, "Mr. K", "I Love My Students");
  printf(" looking for [%s: %s]\n", "Mr. K", "I Love My Students");
  if (find_s1 == NULL) 
	printf("  song not found (O_O)\n");
  else {
    printf("  song found! ('U') ");
    print_songs(find_s1);
  }
  printf("=================================================\n\n");
  
  printf("--- TESTING search_artist ---\n\n");
  find_a0 = search_artist(lib, s8->artist);
  printf(" looking for [%s: %s]\n", s8->artist, s8->name);
  if (find_a0 == NULL) 
	printf("  artist not found (?_?)\n");
  else {
    printf("  song found! (0u<) ");
    print_songs(find_a0);
  }
  find_a1 = search_song(lib, "Mr. K", "I'm Not Sarcastic");
  printf(" looking for [%s: %s]\n", "Mr. K", "I Love My Students");
  if (find_a1 == NULL) 
	printf("  song not found (O_O)\n");
  else {
    printf("  song found! ('U') ");
    print_songs(find_a1);
  }
  printf("=================================================\n\n");
  
  printf("--- TESTING delete_song ---\n\n");
  printf("Deleting\n ");
  print_song(s2);
  lib = delete_song(lib, s2);
  print_lib(lib);
  
  printf("Deleting\n ");
  print_song(s8);
  lib = delete_song(lib, s8);
  print_lib(lib);
  
  printf("=================================================\n\n");
  
  printf("--- TESTING shuffle ---\n\n");
  shuffle(lib);
  
  printf("=================================================\n\n");
  printf("--- TESTING clear_library ---\n\n");
  lib = clear_library(lib);
  
  
  printf("=================================================\n\n");
  
}
