#include <iostream>
#include <fstream>
#include <stdlib.h>

/* ACCEPTED 0.019s */

/* algorithm: sorting
Sort the entries by decreasing ratio (fine/day) and then
in the order they appeared in the input.
*/

#define in cin

using namespace std;

typedef struct {
    int time, fine, index;
    double ratio;
} entry;

int compare(const void *pa, const void *pb) {
    entry a = *(entry *) pa;
    entry b = *(entry *) pb;

    if (a.ratio < b.ratio) {
        return 1;
    } else if (a.ratio > b.ratio) {
        return -1;
    } else {
        return (a.index - b.index);
    }
}

int main() {

    int n, nelements;
    string line;

    in >> n;
    getline(in, line);
    getline(in, line);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << endl;
        in >> nelements;
        entry a[nelements];
        for (int j = 0; j < nelements; j++) {
            a[j].index = j + 1;
            in >> a[j].time >> a[j].fine;
            a[j].ratio = (1.0 * a[j].fine) / a[j].time;
        }
        getline(in, line);
        qsort(a, nelements, sizeof(entry), compare);
        for (int j = 0; j < nelements; j++) {
            (j > 0) ? cout << " " << a[j].index : cout << a[j].index;
        }
        cout << endl;
    }

    return 0;
}
