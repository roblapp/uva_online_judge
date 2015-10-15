#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc
*/

using namespace std;

void printPageOrder(int n) {
    int nearestMult = n;
    while (nearestMult % 4 != 0)
        nearestMult++;
    int a = 1, b = nearestMult, nsheets = nearestMult >> 2;
    bool isBlankA;
    bool isBlankB;
    cout << "Printing order for " << n << " pages:" << endl;
    for (int i = 1; i <= nsheets; i++) {
        if (a > n) {
            isBlankA = true;
        } else {
            isBlankA = false;
        }
        if (b > n) {
            isBlankB = true;
        } else {
            isBlankB = false;
        }
        if (!(isBlankA and isBlankB)) {
            if (isBlankA) {
                cout << "Sheet " << i << ", front: " << b << ", Blank" << endl;
            } else if (isBlankB) {
                cout << "Sheet " << i << ", front: Blank, " << a << endl;
            } else {
                cout << "Sheet " << i << ", front: " << b << ", " << a << endl;
            }
        }
        a++;
        b--;
        if (a > n) {
            isBlankA = true;
        } else {
            isBlankA = false;
        }
        if (b > n) {
            isBlankB = true;
        } else {
            isBlankB = false;
        }
        if (!(isBlankA and isBlankB)) {
            if (isBlankA) {
                cout << "Sheet " << i << ", back : Blank, " << b << endl;
            } else if (isBlankB) {
                cout << "Sheet " << i << ", back : " << a << ", Blank" << endl;
            } else {
                cout << "Sheet " << i << ", back : " << a << ", " << b << endl;
            }
        }
        a++;
        b--;
    }
}

int main() {
    int npages;
    while (cin >> npages and npages != 0) {
        printPageOrder(npages);
    }
    return 0;
}
