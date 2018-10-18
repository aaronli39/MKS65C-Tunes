#ifndef LIST_H
#define LIST_H

struct song_node {char name[100]; char artist[100]; struct song_node * next;};

struct song_node * free_list(struct song_node *);

struct song_node * free_song(struct song_node *, struct song_node *);

void print_songs(struct song_node *);

void print_song(struct song_node *);

struct song_node * make(char* artist, char* name);

struct song_node * insert_front(struct song_node *, char*, char*);

struct song_node * insert_order(struct song_node *, struct song_node *);

struct song_node * find_node(struct song_node *, struct song_node *);

struct song_node * find_artist(struct song_node *, char*);

struct song_node * random_song(struct song_node * n);

struct song_node * remove_song(struct song_node *, struct song_node *);

//helper func

int compare(struct song_node *, struct song_node *);

#endif
