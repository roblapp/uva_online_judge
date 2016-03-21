#include <iostream>
#include <cmath>
#include <sstream>

/*
Accepted: 0.206s
Category: ad-hoc
*/

using namespace std;

int main() {
	string line;
	int x, exp;
	bool first;

	while (getline(cin, line)) {
        stringstream ss(line);
        exp = 8;
        first = true;
        while (ss >> x) {
            if (x != 0) {
                if (first) {
                    if (exp > 1) {
                        if (abs(x) == 1) {
                            (x < 0) ?  cout << "-x^" << exp : cout << "x^" << exp;
                        } else {
                            cout << x << "x^" << exp;
                        }
                    } else if (exp > 0) {
                        if (abs(x) == 1) {
                            (x < 0) ?  cout << "-x" : cout << "x";
                        } else if (x < 0) {
                            cout << "-" << abs(x) << "x";
                        } else {
                            cout << x << "x";
                        }
                    } else {
                        cout << x;
                    }
                    first = false;
                } else {
                    if (exp > 1) {
                        if (abs(x) == 1) {
                            (x < 0) ?  cout << " - " << "x^" << exp : cout << " + x^" << exp;
                        } else if (x < 0) {
                            cout << " - " << abs(x) << "x^" << exp;
                        } else {
                            cout << " + " << x << "x^" << exp;
                        }
                    } else if (exp > 0) {
                        if (abs(x) == 1) {
                            (x < 0) ?  cout << " - " << "x" : cout << " + x";
                        } else if (x < 0) {
                            cout << " - " << abs(x) << "x";
                        } else {
                            cout << " + " << x << "x";
                        }
                    } else {
                        (x < 0) ? cout << " - " << abs(x) :
                            cout << " + " << x;
                    }
                }
            }
            exp--;
        }
        if (first) cout << "0";
        cout << endl;
    }
    return 0;
}
