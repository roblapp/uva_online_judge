#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/* ACCEPTED 0.032s */

#define MAXWORDS 200
#define MAXLINE 100
#define MAX_LEN 10
#define MAXALPHA 26
#define DIFF 97
#define MAXV 200
#define MAX_SIZE 100

/**< type definitions */
typedef struct entry entry;
typedef struct hash_map hash_map;
typedef int t_number;
typedef struct graph graph;
typedef struct vertex vertex;
typedef struct node node;
typedef struct queue queue;

struct vertex {
    int y;
    struct vertex *next;
};

struct graph {
    struct vertex *vertices[MAXV + 1];
    int nvertices;
};

struct entry {
    char key[MAX_LEN];
    t_number value;
    struct entry *next;
};

struct hash_map {
    struct entry *table[MAX_SIZE];
    int size;
};

struct node {
    int x;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
    int size;
};

/**< prototypes */
void init_map(hash_map *h);
entry *entry_allocate(char *s, t_number value);
unsigned hash(char *key);
int insert(hash_map *h, char *s, t_number *value);
bool contains(hash_map *h, char *s);
void show_map(hash_map *h, char *value_format);

node *nalloc( int data ) {
    node *temp = ( node * ) malloc ( sizeof ( node ) );
    temp->x = data;
    temp->next = NULL;
    return temp;
}

void enqueue( queue *q, int data ) {
    node *temp = nalloc( data );

    if ( q->head == NULL )
        q->head = temp;
    else
        q->tail->next = temp;

    q->tail = temp;
    q->size = q->size + 1;
}

int dequeue( queue *q ) {
    int res = 0;

    if ( q->head != NULL ) {
        node *temp = q->head;
        res = temp->x;
        q->head = q->head->next;

        if ( q->head == NULL )
            q->tail = NULL;

		q->size = q->size - 1;
    }

    return res;
}

bool is_empty(queue *q) {
    return (q->size == 0);
}

void init_q( queue *q ) {
    q->head = q->tail = NULL;
    q->size = 0;
}

void init_graph( graph *g ) {
    int i;
    g->nvertices = 0;
    for ( i = 0; i <= MAXV; i++ ) g->vertices[i] = NULL;
}

void init_map(hash_map *h) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) h->table[i] = NULL;
    h->size = 0;
}

void init_dictionary(char *d[]) {
    int i;
    for (i = 0; i < MAXWORDS; i++) {
        d[i] = (char *) malloc(MAX_LEN + 1);
    }
}

void init(hash_map *h, graph *g, char *d[]) {
    init_map(h);
    init_graph(g);
    init_dictionary(d);
}

void clear(hash_map *h, graph *g) {
    init_map(h);
    init_graph(g);
}

entry *entry_allocate(char *s, t_number value) {
    entry *temp = (entry *) malloc (sizeof ( entry ));
    strcpy(temp->key, s);
    temp->value = value;
    temp->next = NULL;
    return temp;
}

/* puts y in x's adjacency list */
void insert_edge( graph *g, int x, int y, bool dir ) {
    vertex *v = ( vertex * ) malloc ( sizeof( vertex ) );
    v->y = y;
    v->next = g->vertices[x];
    g->vertices[x] = v;
    if ( dir ) insert_edge( g, y, x, false );
}

unsigned hash(char *key) {
    char *p = key;
    unsigned h = 0;
    while (*p) {
        h ^= ( h << 5 ) + ( h >> 2 ) + *p;
        p++;
    }
    return h % MAX_SIZE;
}

/* returns the next available value for the next vertex */
int insert(hash_map *h, char *s, t_number *value) {
    unsigned index = hash(s);

    entry *temp = h->table[index];

    while (temp != NULL) {
        if (strcmp(temp->key, s) == 0) {
            return (temp->value);
        }
        temp = temp->next;
    }

    entry *n = entry_allocate(s, *value);
    n->next = h->table[index];
    h->table[index] = n;
    h->size = h->size + 1;
    int res = *value;
    *value = *value + 1;
    return res;
}


bool contains(hash_map *h, char *s) {
    unsigned index = hash(s);
    entry *temp = h->table[index];
    while (temp != NULL) {
        if (strcmp(temp->key, s) == 0 ) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

t_number value(hash_map *h, char *s) {
    unsigned index = hash(s);
    entry *temp = h->table[index];
    while (temp != NULL) {
        if (strcmp(temp->key, s) == 0 ) {
            return temp->value;
        }
        temp = temp->next;
    }
    return (-1);
}

void show_graph( graph *g ) {
    int i;
    vertex *v;

    for ( i = 1; i <= MAXV; i++ )
    {
        v = g->vertices[i];

        if ( v != NULL )
        {
            printf("%i:", i );

            while ( v != NULL )
            {
                printf(" %i", v->y );
                v = v->next;
            }
            printf("\n");
        }
    }
}

void show_map(hash_map *h, char *value_format) {
    int i = 0;
    entry *temp;
    printf("SIZE: %i\n", h->size);
    for ( i = 0; i < MAX_SIZE; i++ ) {
        temp = h->table[i];
        if ( temp != NULL ) {
            while ( temp != NULL ) {
                printf("KEY: %s %p\n", temp->key, temp);
                printf(value_format, temp->value);
                putchar('\n');
                temp = temp->next;
            }
            putchar('\n');
        }
    }
}






/* function that returns true if string s is one character
    different than string t */
bool is_neighbor(char *s, char *t) {
    int i, sl = strlen(s), tl = strlen(t), count = 0;
    if (sl != tl) return false;

    for (i = 0; i < sl && count < 2; i++) {
        if (s[i] != t[i]) count++;
    }

    return (count == 1);
}

int getline_trim(char *s, FILE *fp) {
    char c;
    int i = 0;
    bool seen_char = false;
    while ((c = fgetc(fp)) != EOF && c != '\n') {
        if (!isspace(c)) {
            seen_char = true;
        }
        if (seen_char) {
            s[i++] = c;
        }
    }

    int k = i - 1;

    while (k >= 0 && s[k] == ' ') {
        s[k] = 0;
        k--;
    }

    k++;
    s[k] = '\0';

    return k;
}

int split(char *dst[], char line[]) {
    int i = 0, j = 0, wc = -1, st = 0;

    while (line[i]) {
        if (isalnum(line[i])) {
            if (!st) wc++;
            st = 1;
            dst[wc][j] = line[i];
            j++;
        } else {
            if (st) dst[wc][j] = '\0';
            st = 0;
            j = 0;
        }
        i++;
    }
    if (st) dst[wc][j] = '\0';
    return wc + 1;
}

int bfs(graph *g, int src, int dst) {

    int v = src;
    bool disc[MAXV + 1];
    int parent[MAXV + 1];
    queue q;
    vertex *temp;

    init_q(&q);
    memset(disc, 0, sizeof(disc));
    memset(parent, -1, sizeof(parent));
    disc[v] = true;
    parent[v] = 0;
    enqueue(&q, v);

    while (!is_empty(&q)) {
        v = dequeue(&q);
        if (v == dst) break;
        temp = g->vertices[v];
        while (temp != NULL) {
            if (!disc[temp->y]) {
                disc[temp->y] = true;
                enqueue(&q, temp->y);
                parent[temp->y] = parent[v] + 1;
            }
            temp = temp->next;
        }
    }
    return parent[dst];
}

int main() {

    char *d[MAXWORDS + 1];

    char line[MAXLINE];

    int i, j, k, t, x, ncases;
    int N = 0;
    hash_map h;
    graph g;

    init(&h, &g, d);
    FILE *fp = stdin;

    fscanf(fp, "%i", &ncases);
    getline_trim(line, fp);
    getline_trim(line, fp);

    for (i = 0; i < ncases; i++) {
        clear(&h, &g);
        x = j = 0;
        if (N++) putchar('\n');
        while (getline_trim(line, fp) > 0) {
            if (line[0] == '*') break;
            /* Store in the array */
            strcpy(d[j++], line);
        }

        for (k = 0; k < j - 1; k++) {
            for (t = k + 1; t < j; t++) {
                if (is_neighbor(d[k], d[t])) {
                    /* Insert returns the value that was placed with the key,
                        if the entry was not in the table, otherwise it returns
                        the value associated with the key. Insert takes care of incrementing
                        the x value. */
                    int z = insert(&h, d[k], &x);
                    int y = insert(&h, d[t], &x);

                    insert_edge(&g, z, y, true);
                }
            }
        }

        while (getline_trim(line, fp) > 0) {
            split(d, line);
            int z = value(&h, d[0]);
            int y = value(&h, d[1]);

            printf("%s %i\n", line, bfs(&g, z, y));
        }
    }

    fclose(fp);


    return 0;
}
