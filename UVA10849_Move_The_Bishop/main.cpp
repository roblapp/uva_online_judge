#include <iostream>
#include <cmath>

/*
Accepted: 0.018s
Description: ad-hoc, just a little thinking
Info: draw this out on paper and see the pattern and it becomes
clear that you will always be able to move in 0 (already at that spot),
1, or 2 moves or not possible. Thus, we can detect the pattern and
test for conditions for when to output.
*/

#define read cin

using namespace std;

int main() {
    int i, j, ncases, nqueries, n, sx, sy, ex, ey, rowDist, colDist, soln;
    read >> ncases;
    for (i = 1; i <= ncases; i++) {
        read >> nqueries >> n;
        for (j = 1; j <= nqueries; j++) {
            read >> sx >> sy >> ex >> ey;
            rowDist = abs(ex - sx);
            colDist = abs(ey - sy);
            if (rowDist == colDist && rowDist == 0) {
                cout << "0" << endl;
            } else {
                if (rowDist % 2 == 0) {
                    if (colDist % 2 == 0) soln = (rowDist == colDist) ? 1 : 2;
                    else soln = 0;
                } else {
                    if (colDist & 1) soln = (rowDist == colDist) ? 1 : 2;
                    else soln = 0;
                }
                (soln == 0) ? cout << "no move" << endl : cout << soln << endl;
            }
        }
    }
    return 0;
}
