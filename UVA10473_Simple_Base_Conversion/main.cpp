#include <iostream>
#include <cmath>
#include <sstream>

/*
Accepted: 0.048s
Category: math-base conversion
*/

using namespace std;

int toInt(char c) {
    return (c >= 'A') ? c - 'A' + 10 : c - '0';
}

char toChar(int x) {
    return (x >= 10) ? 'A' + x - 10 : x + '0';
}

string toBaseN(const string &num, int baseFrom, int baseTo) {
    stringstream ss("");
    int N = (int) num.length(), exponent = N - 1;
    double res = 0;
    unsigned long long x;
    for (int i = 0; i < N; i++)
        res += toInt(num[i])*pow(baseFrom, exponent--);

    x = (unsigned long long) res;
    if (x == 0) return "0";
    while (x > 0) {
        ss << toChar(x%baseTo);
        x /= baseTo;
    }
    string temp = ss.str();
    return string(temp.rbegin(), temp.rend());
}

int main() {
	string num;

	while (cin >> num and num[0] != '-') {
        if (num.length() > 2 and num.substr(0,2) == "0x")
            cout << toBaseN(num.substr(2), 16, 10) << endl;
        else
            cout << "0x" << toBaseN(num, 10, 16) << endl;
	}

    return 0;
}
