#include <iostream>
#include <vector>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing, encoding/decoding
Algorithm: ad-hoc
*/

using namespace std;

#define ASCII_DIFF 'a'
#define NALPHA 26

int computeDiff(char ca, char cb) {
    int diff = 0;
    if (cb > ca)
        diff = ('z' - cb + 1) + (ca - ASCII_DIFF);
    else if (cb < ca)
        diff = ca - cb;
    return diff;
}

int getDiff(string &sa, string &sb, int N) {
    int diff = computeDiff(sa[0], sb[0]);
    for (int i = 1; i < N; i++)
        if (computeDiff(sa[i], sb[i]) != diff)
            return -1;
    return diff;
}

int main() {
	int ncases, index;
	string line, token, firstWord;

	cin >> ncases; getline(cin, line); /* drain newline */
	while (ncases--) {
        getline(cin, line);
        getline(cin, firstWord);
        stringstream ss(line);
        bool used[NALPHA] = {false};
        while (ss >> token)
            if (token.length() == firstWord.length() and (index = getDiff(token, firstWord, token.length())) > -1)
                used[index] = true;
        for (int i = 0; i < NALPHA; i++)
            if (used[i])
                cout << (char)(i + 'a');
        cout << endl;
	}
    return 0;
}
