#include <iostream>
/*
Accepted: 0.000s
Description: ad-hoc
*/
using namespace std;

long long digitSum(long long x) {
    long long sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    long long n;
    while (cin >> n and n != 0) {
        while ((n = digitSum(n)) >= 10);
        cout << n << endl;
    }
    return 0;
}
