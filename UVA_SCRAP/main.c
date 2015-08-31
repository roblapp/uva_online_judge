#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50
#define MAX_ELEMENTS 100

typedef struct {
    int position;
    char s[MAXLEN + 1];
    int unsorted_value;
} element;

int compare(const void *a, const void *b) {
    element element_a = *((element *) a);
    element element_b = *((element *) b);
    return element_a.unsorted_value == element_b.unsorted_value ?
        element_a.position - element_b.position :
        element_a.unsorted_value - element_b.unsorted_value;
}

void compute_unsorted_value(element *a) {
    int i, j, len = strlen(a->s), count = 0;
    for (i = 0; i < len - 1; i++) {
        for (j = i; j < len; j++) {
            if (a->s[i] > a->s[j]) {
                count++;
            }
        }
    }
    a->unsorted_value = count;
}

int my_getline(char *s, FILE *fp) {
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF && c != '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int main() {
    int i, j, ncases, n, m, N = 0;
    element e[MAX_ELEMENTS];
    FILE *fp = stdin; /* fopen("test.txt", "r"); */
    fscanf(fp, "%i", &ncases);
    for (i = 0; i < ncases; i++) {
        fscanf(fp, "%i %i", &m, &n);
        fgetc(fp);
        for (j = 0; j < n; j++) {
            e[j].position = j;
            my_getline(e[j].s, fp);
            compute_unsorted_value(&e[j]);
        }
        qsort(e, n, sizeof(element), compare);
        if (N++) {
            putchar('\n');
        }
        for (j = 0; j < n; j++) {
            printf("%s\n", e[j].s);
        }
    }
    fclose(fp);

    return 0;
}
