#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

/*
Accepted: 0.000s
Description: topological sort, (turned out to be ad-hoc)
Info: see https://uva.onlinejudge.org/board/viewtopic.php?f=2&t=9749
*/

using namespace std;

#define NALPHA 26
#define DIFF 'A'

struct Entry {
    char c;
    int order;
};

bool compare(Entry ea, Entry eb) {
    if (ea.order < eb.order) return true;
    else if (ea.order > eb.order) return false;
    else return ea.c < eb.c;
}

void process(vector<string> &v) {
    int nrows = (int) v.size(), ncols = 0, order = 1;
    Entry q[NALPHA];
    for (int i = 0; i < NALPHA; i++) {
        q[i].c = (char) (i + DIFF);
        q[i].order = 0;
    }
    for (int i = 0; i < nrows; i++)
        if ((int) v[i].length() > ncols)
            ncols = v[i].length();

    for (int col = 0; col < ncols; col++) {
        for (int row = 0; row < nrows; row++) {
            if (col < (int) v[row].length() && q[v[row][col] - DIFF].order == 0)
                q[v[row][col] - DIFF].order = order++;
        }
    }
    sort(q, q + NALPHA, compare);
    for (int i = 0; i < NALPHA; i++)
        if (q[i].order > 0)
            cout << q[i].c;
    cout << endl;
}

int main() {
	string line;
	vector<string> v;

	while (getline(cin, line)) {
        if (line == "#") {
            process(v);
            v.clear();
        } else
            v.push_back(line);
	}
    return 0;
}
