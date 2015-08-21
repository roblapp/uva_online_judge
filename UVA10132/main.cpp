#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

/* ACCEPTED 0.015s */
/*
Algorithm:
backtracking with pruning

*/

#define MAXN 288
#define MAXLEN 256*8
#define in cin

using namespace std;

struct entry {
    char data[MAXLEN + 1];
    int len;
    bool used;
};

typedef struct entry entry;

void construct_candidates(entry *a[], int k, int n, int soln_len, int c[], int *ncandidates) {
    *ncandidates = 0;
    for (int i = k + 1; i < n; i++) {
        if (a[i]->len == soln_len - a[k]->len && !a[i]->used) {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
    }
}

void copy_soln(char *s, char *a, char *b, int la, int lb) {
    int k = 0;
    for (int i = 0; i < la; i++) {
        s[k++] = a[i];
    }
    for (int i = 0; i < lb; i++) {
        s[k++] = b[i];
    }
    s[k] = 0;
}

bool backtrack(entry *a[], int k, int n, int soln_len, char *prev) {

    if (k == n) {
        cout << prev << endl;
        return true;
    }

    if (a[k]->used) {
        return backtrack(a, k + 1, n, soln_len, prev);
    }

    int c[MAXN];
    int ncandidates;

    construct_candidates(a, k, n, soln_len, c, &ncandidates);

    for (int i = 0; i < ncandidates; i++) {
        char temp[MAXLEN + 1];
        copy_soln(temp, a[k]->data, a[c[i]]->data, a[k]->len, a[c[i]]->len);
        a[c[i]]->used = true;
        if (k == 0 || strcmp(temp, prev) == 0) {
            if (backtrack(a, k + 1, n, soln_len, temp)) {
                return true;
            }
        }
        copy_soln(temp, a[c[i]]->data, a[k]->data, a[c[i]]->len, a[k]->len);
        if (k == 0 || strcmp(temp, prev) == 0) {
            if (backtrack(a, k + 1, n, soln_len, temp)) {
                return true;
            }
        }
        a[c[i]]->used = false;
    }
    return false;
}

int main() {

    int n, len, sum, k, element_len, npairs;
    string line;
    entry *a[MAXN];

    in >> n;
    getline(in, line);
    getline(in, line);

    while (n--) {
        k = sum = 0;
        while (getline(in, line) && (len = line.length()) > 0) {
            entry *temp = new entry;
            int x = line.copy(temp->data, len);
            temp->data[x] = 0;
            temp->used = false;
            temp->len = len;
            a[k++] = temp;
            sum += len;
        }
        npairs = (k >> 1);
        element_len = sum / npairs;
        backtrack(a, 0, k, element_len, 0);
        for (int i = 0; i < k; i++) {
            delete a[i];
        }
    }

    return 0;
}
