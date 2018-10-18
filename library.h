#ifndef PLAYER_H
#define PLAYER_H

struct library {struct song_node * letter[27];};

void add_song(struct library *, struct song_node *);

struct song_node * search_artist(struct library*, char*);

struct song_node * search_song(struct library*, char*, char*);

void print_by_artist(struct library*, char*);

void print_library(struct library*);

void print_by_letter(struct library*, char);

struct library* delete_song(struct library*, struct song_node *);

void shuffle(struct library*);

void clear_library(struct library*);

#endif
