#include <iostream>
#include <algorithm>
#include <sstream>

/*
Accepted: 0.000s
Description: ad-hoc
*/

#define read cin

using namespace std;

void showGrade(int c, int g) {
    stringstream ss;
    ss << "Case " << c << ": ";
    if (g >= 90) ss << "A";
    else if (g >= 80) ss << "B";
    else if (g >= 70) ss << "C";
    else if (g >= 60) ss << "D";
    else ss << "F";
    cout << ss.str() << endl;
}

int main() {
    int i, ncases, a, b, c, d, e, f, g;
    int x[3];
    read >> ncases;
    for (i = 1; i <= ncases; i++) {
        read >> a >> b >> c >> d >> e >> f >> g;
        x[0] = e;
        x[1] = f;
        x[2] = g;
        sort(x, x + 3);
        showGrade(i, a + b + c + d + ((x[2] + x[1]) >> 1));
    }
    return 0;
}
