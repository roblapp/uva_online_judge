#include <iostream>
#include <string>

/*
Accepted: 0.000s
Description: ad-hoc, primality testing
*/

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    else if (n <= 3) return true;
    else if (n % 2 == 0 || n % 3 == 0) return false;
    int i;
    for (i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || (n % (i + 2) == 0)) return false;
    }
    return true;
}

int getInt(char c) {
    if (islower(c)) return (c - 96);
    else return (c - 64 + 26);
}

int main() {
    int i, len;
    string line;
    int sum = 0;
    while (getline(cin, line)) {
        sum = 0;
        for (i = 0, len = line.length(); i < len; i++)
            sum += getInt(line[i]);
        if (sum == 1 || isPrime(sum)) cout << "It is a prime word." << endl;
        else cout << "It is not a prime word." << endl;
    }
    return 0;
}
