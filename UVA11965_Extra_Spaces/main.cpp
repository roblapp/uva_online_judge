#include <iostream>

/*
Accepted: 0.029s
Category: string processing, ad-hoc
Algorithm: ad-hoc
*/

using namespace std;

int main() {
	int ncases, nlines, N = 0;
	string line;

	cin >> ncases;
	while (ncases--) {
        cin >> nlines; getline(cin, line); /* drain newline */
        if (N++)
            cout << endl;
        cout << "Case " << N << ":" << endl;
        for (int i = 0; i < nlines; i++) {
            getline(cin, line);
            bool isPrevSpace = false;
            for (int j = 0; line[j]; j++) {
                if (line[j] == ' ') {
                    if (!isPrevSpace)
                        cout << line[j];
                    isPrevSpace = true;
                } else {
                    cout << line[j];
                    isPrevSpace = false;
                }
            }
            cout << endl;
        }
	}
    return 0;
}
