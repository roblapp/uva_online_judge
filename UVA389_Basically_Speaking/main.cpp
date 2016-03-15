#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

/*
Accepted: 0.335s
Category: math-change of base
*/

using namespace std;

int toInt(char c) {
    return (c >= 'A') ? c - 'A' + 10 : c - '0';
}

char toChar(int x) {
    return (x >= 10) ? 'A' + x - 10 : x + '0';
}

double toBaseTen(string &s, int baseFrom) {
    int N = (int) s.length(), exponent = N - 1;
    double res = 0;
    for (int i = 0; i < N; i++)
        res += toInt(s[i])*pow(baseFrom, exponent--);
    return res;
}

string toBaseN(string &num, int baseFrom, int baseTo) {
    stringstream ss("");
    unsigned long long x = toBaseTen(num, baseFrom);
    if (x == 0) return "0";
    while (x > 0) {
        ss << toChar(x%baseTo);
        x /= baseTo;
    }
    string temp = ss.str();
    return string(temp.rbegin(), temp.rend());
}

int main() {
	string line, res;
	int baseTo, baseFrom;

	while (cin >> line >> baseFrom >> baseTo) {
        res = toBaseN(line, baseFrom, baseTo);
        (res.length() > 7) ? cout << right << setw(7) << "ERROR" << endl :
                cout << right << setw(7) << res << endl;
	}
    return 0;
}
