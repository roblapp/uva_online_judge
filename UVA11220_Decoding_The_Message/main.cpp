#include <iostream>
#include <sstream>

/*
Accepted: 0.006s
Category: string processing, encode/decode
Algorithm: ad-hoc
*/

using namespace std;

int main() {
	int ncases, N = 0;
	string line, token;

	cin >> ncases; getline(cin, line); getline(cin, line); /* drain newline and first empty line */
	while (ncases--) {
        if (N++)
            cout << endl;
        cout << "Case #" << N << ":" << endl;
        while (getline(cin, line) and !line.empty()) {
            stringstream ss(line);
            int pos = 0;
            while (ss >> token)
                if (pos < (int) token.length())
                    cout << token[pos++];
            cout << endl;
        }
	}
    return 0;
}
