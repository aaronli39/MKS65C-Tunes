struct song_node{
    char name[100];
    char artist[100];
    struct song_node *next;
};

struct song_node * table[27];

void print_list(struct node *);

struct node * insert_front(struct node *, int);
struct node * free_list(struct node *);
