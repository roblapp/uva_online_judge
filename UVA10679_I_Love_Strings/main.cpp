#include <iostream>

/*
Accepted: 0.262s
Category: string processing, string comparison, ad-hoc
Algorithm: ad-hoc
*/

using namespace std;

int main() {
	int ns, nq;
	string s, qs;

	cin >> ns;
	while (ns--) {
        cin >> s >> nq;
        while (nq--) {
            cin >> qs;
            if (s.substr(0, qs.size()) == qs)
                cout << "y" << endl;
            else
                cout << "n" << endl;
        }
	}
    return 0;
}
