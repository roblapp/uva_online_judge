#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>

/* ACCEPTED 0.019s */
/*
Algorithm:
ad-hoc/hashing
*/

#define in cin
#define MAX_LEN 100
#define MAX_SIZE 100

using namespace std;

/**< structs */
struct entry {
    char key[MAX_LEN];
    struct entry *next;
};

struct hash_set {
    struct entry *table[MAX_SIZE];
    int size;
};

/**< type definitions */
typedef struct entry entry;
typedef struct hash_set hash_set;

/**< prototypes */
void init_set(hash_set *h);
void clear_table(hash_set *h);
entry *entry_allocate(char *s);
unsigned hash(char *key);
void insert(hash_set *h, char *s);
bool contains(hash_set *h, char *s);


/**< function definitions */
void init_set(hash_set *h) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) h->table[i] = NULL;
    h->size = 0;
}

entry *entry_allocate(char *s) {
    entry *temp = (entry *) malloc (sizeof ( entry ));
    strcpy(temp->key, s);
    temp->next = NULL;
    return temp;
}

void clear_table(hash_set *h) {
    int i = 0;
    entry *temp, *v;
    for (i = 0; i < MAX_SIZE; i++) {
        temp = h->table[i];
        while (temp != NULL) {
            v = temp;
            temp = temp->next;
            free(v);
        }
    }
	init_set(h);
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

void insert(hash_set *h, char *s) {
    unsigned index = hash(s);

    entry *temp = h->table[index];

    while (temp != NULL) {
        if (strcmp(temp->key, s) == 0) {
            return;
        }
        temp = temp->next;
    }

    entry *n = entry_allocate(s);
    n->next = h->table[index];
    h->table[index] = n;
    h->size = h->size + 1;
}

bool contains(hash_set *h, char *s) {
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

int main() {

    int k = 1, nreq, nrfp, req_met, comp_req, soln_req, N = 0;
    double temp_cost, soln_cost;
    char line[MAX_LEN];
    char soln_company[MAX_LEN];
    char temp_company[MAX_LEN];
    hash_set h;
    FILE *fp = stdin;


    while (fscanf(fp, "%i %i", &nreq, &nrfp) == 2 && (nreq != 0 || nrfp != 0)) {
        init_set(&h);
        getline_trim(line, fp);
        soln_req = soln_cost = 0;
        for (int i = 0; i < nreq; i++) {
            getline_trim(line, fp);
            insert(&h, line);
        }
        for (int i = 0; i < nrfp; i++) {
            getline_trim(temp_company, fp); /* read company name */
            fscanf(fp, "%lf %i", &temp_cost, &comp_req);
            getline_trim(line, fp); /* drain the new line character */
            req_met = 0;
            for (int j = 0; j < comp_req; j++) {
                getline_trim(line, fp);
                if (contains(&h, line)) {
                    req_met++;
                }
            }
            if (req_met > soln_req) {
                soln_req = req_met;
                soln_cost = temp_cost;
                strcpy(soln_company, temp_company);

            } else if (req_met == soln_req) { /* if they have the same requirements, check the price */
                if (temp_cost < soln_cost) {
                    strcpy(soln_company, temp_company);
                    soln_cost = temp_cost;
                }
            }
        }
        if (N++) putchar('\n');
        printf("RFP #%i\n%s\n", k++, soln_company);
        clear_table(&h);
    }

    fclose(fp);

    return 0;
}
