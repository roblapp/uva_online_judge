#include <iostream>
#include <cmath>

/*
Accepted: 0.000s
Description: ad-hoc/floating point accuracy
*/

#define read cin

using namespace std;

int main() {
    int ncases;
    double a, b, x, y, diffX, diffY;
    long long solx, soly;

    read >> ncases;
    while (ncases--) {
        read >> a >> b;
        x = (a + b) / 2;
        diffX = x - floor(x);
        if (diffX > 0.0f) cout << "impossible" << endl;
        else {
            y = x - b;
            diffY = y - floor(y);
            if (diffY > 0.0f) cout << "impossible" << endl;
            solx = (int) max(x,y);
            soly = (int) min(x,y);
            if (solx >= 0 and soly >= 0) cout << solx << " " << soly << endl;
            else {
                y = (a + b) / 2;
                diffY = y - floor(y);
                if (diffY > 0.0f) cout << "impossible" << endl;
                else {
                    x = a - y;
                    diffX = x - floor(x);
                    if (diffX > 0.0f) cout << "impossible" << endl;
                    solx = (int) max(x,y);
                    soly = (int) min(x,y);
                    if (solx >= 0 and soly >= 0) cout << solx << " " << soly << endl;
                    else cout << "impossible" << endl;
                }
            }
        }
    }
    return 0;
}
