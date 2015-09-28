#include <iostream>
#include <cmath>
/*
Accepted: 0.000s
Description: ad hoc, very easy calculation
Info: watch out for negative numbers
*/
using namespace std;

int main() {
    int ncases, x;
    cin >> ncases;
    while (ncases--) {
        cin >> x;
        cout << abs((((((567*x / 9 + 7492) * 235)/47) - 498) % 100)/10) << endl;
    }
    return 0;
}
