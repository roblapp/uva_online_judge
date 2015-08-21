#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/* ACCEPTED 0.012s */

#define MAX_LEN 1000
#define MAX_SIZE 1000

int getline(char s[]) {
    char c;
    int i = 0;

    while ( ( c = getchar() ) != EOF && c != '\n' )
        s[i++] = c;

    s[i] = '\0';

    return i;
}

int split_to_intarray(int a[], char line[]) {
    int i = 0, j = 0, wc = -1, st = 0;
    int tempi = 0;
    bool seen_neg = false;
    while (line[i]) {
        if (isdigit( line[i] ) || line[i] == '-') {
            if (!st) wc++;
            st = 1;
            if (line[i] == '-') {
                seen_neg = true;
            } else {
                tempi = tempi * 10 + (line[i] - 48);
            }
            j++;
        } else {
            if (st) {
                if (seen_neg) tempi *= -1;
                a[wc] = tempi;
                tempi = 0;
                seen_neg = false;
            }
            st = 0;
            j = 0;
        }
        i++;
    }
    if (st) {
        if (seen_neg) tempi *= -1;
        a[wc] = tempi;
    }
    return wc + 1;
}

int compare(const void *pa, const void *pb) {
    return *((int *) pa) - *((int *) pb);
}

void init_int_array(int a[]) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) a[i] = 0;
}

bool contains(int a[], int element, int low, int high) {
    if (high < low) {
        return false;
    } else {

        int mid = (high + low) / 2;

        if (a[mid] < element) {
            return contains(a, element, mid + 1, high);
        } else if (a[mid] > element) {
            return contains(a, element, low, mid - 1);
        } else {
            return true;
        }
    }
}

int main() {

    char line[MAX_LEN];
    int a[MAX_LEN], b[MAX_LEN];
    int i, sizea, sizeb;
    int b_found_a, a_found_b;

    while (getline(line) > 0) {

        init_int_array(a);
        init_int_array(b);

        b_found_a = a_found_b = 0;

        sizea = split_to_intarray(a, line);
        getline(line);

        sizeb = split_to_intarray(b, line);

        qsort(a, sizea, sizeof(int), compare);
        qsort(b, sizeb, sizeof(int), compare);

        for (i = 0; i < sizea; i++) {
            if (contains(b, a[i], 0, sizeb - 1)) {
                a_found_b++;
            }
        }

        if (a_found_b == 0) {
            printf("A and B are disjoint\n");
        } else if (a_found_b < sizea){
            if (a_found_b == sizeb) {
                printf("B is a proper subset of A\n");
            } else {
                printf("I'm confused!\n");
            }
        } else {
            for (i = 0; i < sizea; i++) {
                if (contains(a, b[i], 0, sizea)) {
                    b_found_a++;
                }
            }
            if (b_found_a == sizeb) {
                printf("A equals B\n");
            } else {
                printf("A is a proper subset of B\n");
            }
        }
    }

    return 0;
}
