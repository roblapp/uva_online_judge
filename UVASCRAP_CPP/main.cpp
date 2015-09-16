#include <iostream>

using namespace std;

bool isLeapYear(long long year) {
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    return false;
}

bool isHuluculu(long long year) {
    return (year % 15 == 0);
}

bool isBulukulu(long long year) {
    return isLeapYear(year) && (year % 55 == 0);
}

int main() {
    int N = 0;
    long long year;
    bool foundOne;

    while (cin >> year) {
        if (N++) cout << endl;
        foundOne = false;
        if (isLeapYear(year)) {
            foundOne = true;
            cout << "This is a leap year." << endl;
        }
        if (isHuluculu(year)) {
            foundOne = true;
            cout << "This is huluculu festival year." << endl;
        }
        if (isBulukulu(year)) {
            foundOne = true;
            cout << "This is bulukulu festival year." << endl;
        }
        if (!foundOne) {
            cout << "This is an ordinary year." << endl;
        }

    }
    return 0;
}
