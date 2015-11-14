#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc counting problem
*/

using namespace std;

int main() {
    unsigned long long n, temp;
    while (cin >> n) {
        temp = (n*n + (n << 1) - 1) >> 1;
        cout << (temp + (temp - 2) + (temp - 4)) << endl;
    }
    return 0;
}
