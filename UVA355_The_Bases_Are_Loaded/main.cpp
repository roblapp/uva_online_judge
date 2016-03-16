#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>

/*
Accepted: 0.003s
Category: math-base conversion
Algorithm: base conversion
*/

using namespace std;

int toInt(char c) {
    return (c >= 'A') ? c - 'A' + 10 : c - '0';
}

char toChar(int x) {
    return (x >= 10) ? 'A' + x - 10 : x + '0';
}

void toBaseN(string &s, int baseFrom, int baseTo) {
    stringstream ss("");
    int N = (int) s.length(), exponent = N - 1;
    double res = 0;
    unsigned long long x;

    for (int i = 0; i < N; i++) {
        if (toInt(s[i]) >= baseFrom) {
            cout << s << " is an illegal base " << baseFrom << " number" << endl;
            return;
        }
        res += toInt(s[i])*pow(baseFrom, exponent--);
    }
    x = (unsigned long long) res;
    if (x == 0) {
        cout << s << " base " << baseFrom << " = 0 base " << baseTo << endl;
        return;
    }
    while (x > 0) {
        ss << toChar(x%baseTo);
        x /= baseTo;
    }
    string temp = ss.str();
    reverse(temp.begin(), temp.end());
    cout << s << " base " << baseFrom << " = " << temp << " base " << baseTo << endl;
}

int main() {
	int baseFrom, baseTo;
	string num;

	while (cin >> baseFrom >> baseTo >> num)
        toBaseN(num, baseFrom, baseTo);

    return 0;
}
