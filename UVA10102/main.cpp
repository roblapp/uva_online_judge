#include <iostream>
#include <limits.h>
#include <ctype.h>
#include <vector>

/* ACCEPTED 0.059s */

#define MAXN 500
#define in cin

using namespace std;

typedef struct {
    int x, y;
} point;

int iabs(int n) {
    return (n >= 0) ? n : -n;
}

int dist(point *a, point *b) {
    return (iabs(a->x - b->x) + iabs(a->y - b->y));
}

int main() {

    int n, k, soln, calc;
    string line;
    vector<point> threes;
    vector<point> ones;
    int d[MAXN][MAXN];

    while (in >> n) {
        getline(in, line); /* Chomp remaining line */
        soln = INT_MIN;
        for (int i = 0; i < n; i++) {
            getline(in, line);
            k = 0;
            int len = line.length();
            for (int j = 0; j < len; j++) {
                if (isdigit(line[j])) {
                    if (line[j] == '3') {
                        point p;
                        p.x = i;
                        p.y = k;
                        threes.push_back(p);
                        d[i][k] = 0;
                    } else if (line[j] == '1') {
                        point p;
                        p.x = i;
                        p.y = k;
                        ones.push_back(p);
                        d[i][k] = INT_MAX;
                    } else {
                        d[i][k] = INT_MAX;
                    }
                    k++;
                }
            }
        }
        for (vector<point>::iterator it_ones = ones.begin(); it_ones != ones.end(); it_ones++) {
            point p = *it_ones;
            for (vector<point>::iterator it_threes = threes.begin(); it_threes != threes.end(); it_threes++) {
                point home = *it_threes;
                calc = dist(&p, &home);
                d[p.x][p.y] = min(d[p.x][p.y], calc);
            }
        }
        for (vector<point>::iterator it_ones = ones.begin(); it_ones != ones.end(); it_ones++) {
            point p = *it_ones;
            if (d[p.x][p.y] > soln) {
                soln = d[p.x][p.y];
            }
        }
        threes.clear();
        ones.clear();
        cout << soln << endl;
    }

    return 0;
}
