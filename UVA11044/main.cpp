#include <iostream>

/*
Accepted: 0.000s
Description: ad hoc, simple calculation
Info: The picture in this problem is meant to make you
think MUCH harder than this problem is.
*/
using namespace std;

int main() {
    int ncases, rows, cols, x, y;
    cin >> ncases;
    while (ncases--) {
        cin >> rows >> cols;
        if ((rows - 2) % 3 == 0) x = (rows - 2) / 3;
        else if ((rows - 1) % 3 == 0) x = (rows - 1) / 3;
        else x = rows / 3;
        if ((cols - 2) % 3 == 0) y = (cols - 2) / 3;
        else if ((cols - 1) % 3 == 0) y = (cols - 1) / 3;
        else y = cols / 3;
        cout << (x * y) << endl;
    }
    return 0;
}
