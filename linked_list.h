struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *);

struct song_node * insert_front(struct song_node *, char *, char *);

struct song_node * insert_order(struct song_node *, char *, char *);

struct song_node * insert_name(struct song_node *, char *, char *);

struct song_node * find_song(struct song_node *, struct song_node *);

struct song_node * find_artist(struct song_node *, char *);

struct song_node * random(struct song_node *);

struct song_node * remove(struct song_node *, struct song_node *);

struct song_node * free_list(struct song_node *);
