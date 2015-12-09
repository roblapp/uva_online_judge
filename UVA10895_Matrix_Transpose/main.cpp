#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: data structures - graphs/adjacency lists
*/

using namespace std;

#define read cin
#define MAXN 10000

typedef struct {
    int col, value;
} Data;

int main() {
    int nrows, ncols, nelements, x, col;
    Data d;
    vector<Data> g[MAXN];
    vector<int> values;

    while (read >> nrows >> ncols) {
        for (int i = 0; i < MAXN; i++) g[i].clear();
        for (int i = 0; i < nrows; i++) {
            read >> nelements;
            values.clear();
            for (int j = 0; j < nelements; j++) {
                read >> x;
                values.push_back(x);
            }
            for (int j = 0; j < nelements; j++) {
                read >> x;
                col = values[j] - 1;
                d.col = i + 1;
                d.value = x;
                /* row i, column col becomes row col column i */
                g[col].push_back(d);
            }
        }
        cout << ncols << " " << nrows << endl;
        int k;
        for (int i = 0; i < ncols; i++) {
            vector<Data> v = g[i];
            k = (int) v.size();
            cout << k;
            for (int j = 0; j < k; j++)
                cout << " " << v[j].col;
            cout << endl;
            for (int j = 0; j < k; j++)
                (j == 0) ? cout << v[j].value : cout << " " << v[j].value;
            cout << endl;
        }
    }
    return 0;
}
