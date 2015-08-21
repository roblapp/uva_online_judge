#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* ACCEPTED 0.009s */

/*** HASH MAP ***/
#define MAX_LEN 30
#define MAX_SIZE 1000
#define MAXN 5000

/**< type definitions */
typedef struct entry entry;
typedef struct hash_map hash_map;
typedef int t_number;

/**< structs */
struct entry {
    char key[MAX_LEN];
    t_number value;
    struct entry *next;
};

struct hash_map {
    struct entry *table[MAX_SIZE];
    int size;
};


/**< prototypes */
void init_map(hash_map *h);
void clear_map(hash_map *h);
entry *entry_allocate(char *s, t_number value);
unsigned hash(char *key);
int insert(hash_map *h, char *s, t_number *value);


void init_map(hash_map *h) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) h->table[i] = NULL;
    h->size = 0;
}

entry *entry_allocate(char *s, t_number value) {
    entry *temp = (entry *) malloc (sizeof ( entry ));
    strcpy(temp->key, s);
    temp->value = value;
    temp->next = NULL;
    return temp;
}

unsigned hash(char *key) {
    char *p = key;
    unsigned h = 0;
    while (*p) {
        h ^= (h << 5) + (h >> 2) + *p;
        p++;
    }
    return h % MAX_SIZE;
}

int insert(hash_map *h, char *s, t_number *value) {
    unsigned index = hash(s);
    entry *temp = h->table[index];
    while (temp != NULL) {
        if (strcmp(temp->key, s) == 0) {
            return temp->value;
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

char *int_to_string(int x) {

    char *res = (char *) malloc(30);
    char temp[30];
    int i = 0, y, DIFF = 48, k = 0;
    if (x == 0) {
        res[0] = '0';
        res[1] = 0;
        return res;
    }

    y = x;
    if (x < 0) y = -x;

    while (y > 0) {
        temp[i++] = (y % 10) + DIFF;
        y /= 10;
    }

    if (x < 0) res[k++] = '-';

    while (--i >= 0) {
        res[k++] = temp[i];
    }

    res[k] = 0;

    return res;
}

int main() {

    int i, j, x, y, k = 1, t = 1;
    int p[MAXN];
    bool in_tree[MAXN];
    bool is_tree = true;

    for (i = 0; i < MAXN; i++) p[i] = -1;
    for (i = 0; i < MAXN; i++) in_tree[i] = false;

    hash_map h;
    init_map(&h);

    while (scanf("%i %i", &x, &y) == 2 && (x != -1 || y != -1)) {
        if (x == 0 && y == 0) {
            if (is_tree) { /* still a candidate, process */
                int root_count = 0;
                for (i = 1; i < MAXN && root_count < 2; i++) {
                    if (in_tree[i] && p[i] == -1) root_count++;
                }
                if (root_count > 1) is_tree = false;
            }
            if (is_tree) printf("Case %i is a tree.\n", t++);
            else printf("Case %i is not a tree.\n", t++);
            k = 1;
            init_map(&h);
            is_tree = true;
            for (i = 0; i < MAXN; i++) p[i] = -1;
            for (i = 0; i < MAXN; i++) in_tree[i] = false;
        } else if (is_tree) {
            /* get mapping value. x is a parent of y */
            x = insert(&h, int_to_string(x), &k);
            y = insert(&h, int_to_string(y), &k);
            in_tree[y] = in_tree[x] = true;

            if (p[y] != -1) { /* item already has a parent. not a tree. */
                is_tree = false;
                continue;
            }
            p[y] = x;
            j = x;
            while (p[j] != -1 && p[j] != y) {
                j = p[j];
            }
            if (p[j] != -1) { /* Item already has a parent */
                is_tree = false;
                continue;
            }
            /* if we get here we're okay */
        }
    }

    return 0;
}
