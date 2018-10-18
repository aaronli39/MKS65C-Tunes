#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

// helper methods
int compare(struct song_node * s1, struct song_node * s2) {
    if (strcmp(s1  ->  artist, s2  ->  artist) == 0) {
        return strcmp(s1  ->  name, s2  ->  name);
    } 
	return strcmp(s1  ->  artist, s2  ->  artist);
}

struct song_node * find_prev(struct song_node * song, struct song_node * inp) {
    struct song_node * temp = song;
    struct song_node * prev;
    int comp;

    while (0 > (compare(temp, inp)) && comp != 0 && temp -> next != NULL) {
        prev = temp;
        temp = temp -> next;
    }

    comp = compare(temp, inp);
    if (comp == 0) {
        return prev;
    } if (temp -> next == NULL || comp > 0) {
        return NULL;
    } return prev;
}

// methods
struct song_node * make(char* artist, char* name) {
    struct song_node * temp;
    temp = malloc(sizeof(struct song_node));
    strcpy(temp  ->  artist, artist);
    strcpy(temp  ->  name, name);
    temp  ->  next = NULL;
    return temp;
}

void print_song(struct song_node * song) {
    printf("%s: %s\n", song -> artist, song  ->  name);
}

void print_songs(struct song_node * song) {
    struct song_node * temp = song;
    if (song != NULL) {
        while (temp != NULL) {
            printf("%s: %s | ", temp -> artist, temp -> name);
            temp = temp -> next;
        }
    }
	printf("\n");

}

struct song_node * insert_front(struct song_node * head, char* name, char* artist) {
    struct song_node * temp = make(name, artist);
    temp -> next = head;
    return temp;
}

//goes through and inserts song
struct song_node * insert_order(struct song_node * song, struct song_node * new) {
    struct song_node * temp = song;
    if (temp == NULL) {
        return new;
    }

    if (compare(temp, new) >0) {
        new -> next = song;
        return new;
    } 
	while (temp -> next != NULL && compare(temp -> next, new) < 0) {
        temp = temp -> next;
    }
	new -> next = temp -> next;
    temp -> next = new;
    return song;
}

//if found, returns pointer
//else returns NULL
struct song_node * find_node(struct song_node * song, struct song_node * inp) {
    if (song == NULL) {
        return NULL;
    } 
	struct song_node * temp = song;

    int comp;

    while (temp -> next != NULL && (comp = compare(temp, inp)) < 0 && comp!= 0) {
        temp = temp -> next;
    } 

	if (temp -> next == NULL || comp > 0) {
        return NULL;
    } 

	return temp;
}

struct song_node * find_artist(struct song_node * song, char * artist) {
    struct song_node * temp = song;
    int comp;
    while (temp -> next != NULL && 0 > (comp = strcmp(temp -> artist, artist)) && comp != 0 ) {
        temp = temp -> next;
    } 
	if (temp -> next == NULL || comp > 0) {
        return NULL;
    } 
	return temp;
}

struct song_node * random_song(struct song_node * song) {
    struct song_node * temp = song;
    int count = 0;
    while (temp != NULL) {
        count += 1;
        temp = temp -> next;
    } temp = song;

    count = rand() % count;
    for (; count > 0; count--) {
        temp = temp -> next;
    } return temp;
}

struct song_node * remove_song(struct song_node * song, struct song_node * inp) {
    if (compare(song, inp) == 0) {
        struct song_node * ret = song -> next;
        free(song);
		song = NULL;
        return ret;
    } 
	struct song_node * prev = find_prev(song, inp);

    if (prev == NULL) {
        return song;
    }

    struct song_node * target= prev -> next;
    prev -> next = target -> next;
    free(target);
	target = NULL;
    return song;
}

struct song_node * free_list(struct song_node * song) {
    if (song == NULL) {
        return song;
    } if (song -> next == NULL) {
		printf("freeing [%s: %s]\n", song->artist, song->name);
        free(song);
    } else {;
        free_list(song -> next);
		printf("freeing [%s: %s]\n", song->artist, song->name);
        free(song);
    } 
	return song;
}
