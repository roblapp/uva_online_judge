#include <iostream>
#include <sstream>

/*
Accepted: 0.000s
Category: math-base conversion
*/

using namespace std;

string toBase2(int x) {
    stringstream ss("");
    while (x > 0)
        ss << x % 2, x /= 2;
    string temp = ss.str();
    while (temp.size() < 13)
        temp.append("0");
    return string(temp.rbegin(), temp.rend());
}

int main() {
	int ncases, x, y;
	string op;

	cin >> ncases;
	while (ncases--) {
        cin >> hex >> x >> op >> hex >> y;
        cout << toBase2(x) << " " << op << " " << toBase2(y) << " = ";
        (op == "+") ? cout << x + y << endl : cout << x - y << endl;
	}
    return 0;
}
