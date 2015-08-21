#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ACCEPTED 0.168s */

/* use previously written hash table. Should
re-write it and create a pre-fab hash set data structure. I did
this problem on first try after not using C in some months.*/

#define TABLESIZE 1000
#define MAXLEN 250
#define MAXWORDS 120000
#define TRUE 1
#define FALSE 0


/* MY PRE-DEFINED HASH TABLE DATA STRUCTURE */
struct entry {
    char key[MAXLEN + 1];
    int value;
    struct entry *next;
};

typedef struct entry entry;

entry *table[TABLESIZE];

void init() {
    int i;
    for ( i = 0; i < TABLESIZE; i++ ) table[i] = NULL;
}

entry *entry_allocate( char *key, int value ) {
    entry *temp = ( entry * ) malloc ( sizeof ( entry ) );
    strcpy( temp->key, key );
    temp->value = value;
    temp->next = NULL;
    return temp;
}

unsigned hash( char *key ) {
    char *p = key;
    unsigned h = 0;

    while ( *p ) {
        h ^= ( h << 5 ) + ( h >> 2 ) + *p;
        p++;
    }
    return h % TABLESIZE;
}

int search( char * key ) {
    unsigned index = hash( key );

    entry *temp = table[index];

    while ( temp != NULL ) {
        if ( strcmp( temp->key, key ) == 0 ) {
            return TRUE;
        }
        temp = temp->next;
    }

    return FALSE;
}

int get_value( char *key ) {
    unsigned index = hash( key );

    entry *temp = table[index];

    while ( temp != NULL ) {
        if ( strcmp( temp->key, key ) == 0 ) {
            return temp->value;
        }
        temp = temp->next;
    }

    return 0;
}

void insert( char *key, int value ) {
    unsigned index = hash( key );

    entry *temp = table[index];

    while ( temp != NULL ) {
        if ( strcmp( temp->key, key ) == 0 ) {
            return;
        }
        temp = temp->next;
    }

    entry *n = entry_allocate( key, value );
    n->next = table[index];
    table[index] = n;
}
/* END MY PRE-DEFINED HASH TABLE DATA STRUCTURE */

/* here is a method that splits a string up into 2 substrings
and tests if the each of the substring is contained in the table*/
int substring(char src[], int split, int len) {
    char *res[2];
    res[0] = (char *) malloc(sizeof(split + 1));
    res[1] = (char *) malloc(sizeof(len - split + 1));

    int i, k = 0;
    for (i = 0; i < split; i++) {
        res[0][i] = src[k++];
    }
    res[0][i] = 0;
    for (i = 0; i < len - split + 1; i++) {
        res[1][i] = src[k++];
    }
    res[1][i] = 0;

    if (search(res[0]) && search(res[1])) {
        printf("%s\n", src);
        return TRUE;
    }

    return FALSE;
}

int getline(char s[]) {
    char c;
    int i = 0;

    while ( ( c = getchar() ) != EOF && c != '\n' )
        s[i++] = c;

    s[i] = '\0';

    return i;
}

int main() {

    char in[MAXLEN];
    char *temp[MAXWORDS];
    int i = 0, j, k;

    while (getline(in)) {

        temp[i] = (char *) malloc(MAXLEN);
        strcpy(temp[i], in);
        insert(in, 0);
        i++;
    }

    for (j = 0; j < i; j++) {
        int len = strlen(temp[j]);
        for (k = 1; len > 1 && k < len && !substring(temp[j], k, len); k++);
    }

    return 0;
}


