#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "linked_list.h"

// helpers
struct library * create_lib() {
    struct library * lib = calloc(sizeof(struct song_node), 27);
    return lib;
}

void print_lib(struct library * lib) {
    printf("===============LIBRARY===============\n");
    if (lib != NULL) {
        int i;
        for (i = 0; i < 26; i++) {
            if ((lib -> letter)[i] != NULL) {
                // go from a-z
                printf("===%c===\n", (char) (i + 65));
                // now print the linked-list
                print_songs((lib -> letter)[i]);
            }
        } if ((lib -> letter)[26] != NULL) { // if there are symbol names
            printf("=======Other Symbols=======\n");
            // print em
            print_songs((lib -> letter)[26]);
        }
    }
    printf("=============END LIBRARY=============\n");
}

struct library * add_song(struct library * lib, struct song_node * song) {
    int first = (song -> artist)[0];
    int place = first - 65;

    if (first >= 65 && first <= 90) {
        lib -> letter[place] = insert_order((lib -> letter)[place], song);
    } else {
        lib -> letter[26] = insert_order((lib -> letter)[26], song);
    }
	return lib;
}

void print_by_letter(struct library * lib, char temp) {
    if (temp >= 65 && temp <= 90) {
        printf("%c list", temp);
        temp -= 65;
    } else if (temp >= 97 && temp <= 122) {
        temp -= 32;
        printf("%c list", temp);
        temp -= 65;
    } else {
        printf("%c list", temp);
        temp = 26;
    }
    print_songs(lib -> letter[temp]);
}

void print_by_artist(struct library * lib, char * artist) {
    printf("searching for [%s]\n", artist);
    struct song_node * temp = search_artist(lib, artist);
    if (temp == NULL) {
        printf("artist not found!\n");
    } else {
        while(temp != NULL && strcmp(temp -> artist, artist) == 0) {
            printf("%s: %s | ", temp -> artist, temp -> name);
            temp = temp -> next;
        }
    }
}

struct song_node * search_artist(struct library * lib, char* artist) {
    int place = artist[0];
    if (place >= 65 && place <= 90) {
        place -= 65;
    } else {
        place = 26;
    } struct song_node * temp = lib -> letter[place];
    while (temp != NULL) {
        if (strcmp(temp -> artist, artist) == 0) {
            return temp;
        } temp = temp -> next;
    } return NULL;
}

struct song_node * search_song(struct library * lib, char * name, char * artist) {
    struct song_node * temp = search_artist(lib, artist);
    while (temp != NULL) {
        if (strcmp(temp -> artist, artist) == 0 && strcmp(temp -> name, name) == 0) {
            return temp;
        } temp = temp -> next;
    } return NULL;
}

struct song_node * pre_search(struct library * lib, char * name, char * artist) {
    struct song_node * temp = search_artist(lib, artist);
    if (temp != NULL) {
        struct song_node * pre = NULL;
        while (temp != NULL) {
            if (strcmp(temp -> artist, artist) == 0 && strcmp(temp -> name, name) == 0) {
                return pre;
            } pre = temp;
            temp = temp -> next;
        }
    } return NULL;
}


void shuffle(struct library * lib) {
    int i;
    struct song_node * random;
    struct song_node * temp;
    for (i = 0; i < 5; i++) {
        temp = NULL;
        while(temp == NULL) {
            temp = lib -> letter[rand() % 27];
        }
        random = random_song(temp);
        print_song(random);
    }
}

struct library * delete_song(struct library * lib, struct song_node * song) {
    int place = song -> artist[0];
    if (search_song(lib, song -> name, song -> artist) == NULL) {
        return lib;
    } struct song_node * pre = pre_search(lib, song -> name, song -> artist);

    if (pre != NULL) {
        struct song_node * rem = pre -> next;
        pre -> next = pre -> next -> next;
        free(rem);
        return lib;
    } else {
        if (place >= 65 && place <= 90) {
            place -= 65;
        } else {
            place = 26;
        } struct song_node * rem = lib -> letter[place];
        lib -> letter[place] = lib -> letter[place]  ->  next;
        free(rem);
    } return lib;
}

void clear_library(struct library * lib) {
    int i;
    for (i = 0; i < 27; i++) {
        lib -> letter[i] = free_list(lib -> letter[i]);
    } free(lib);
}
