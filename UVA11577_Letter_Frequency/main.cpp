#include <iostream>
#include <vector>

/*
Accepted: 0.033s
Category: string processing, frequency counting
Algorithm: frequency counting
*/

using namespace std;

#define NALPHA 26
#define ASCII_DIFF 'a'

int main() {
	int ncases, maxVal;
	string line;
	vector<int> freq;

	cin >> ncases; getline(cin, line); /* Drain newline */
	while (ncases--) {
        getline(cin, line);
        maxVal = 0;
        freq.assign(NALPHA, 0);
        for (int i = 0; line[i]; i++)
            if (isalpha(line[i]))
                maxVal = max(maxVal, ++freq[tolower(line[i])-ASCII_DIFF]);
        for (int i = 0; i < NALPHA; i++)
            if (freq[i] == maxVal)
                cout << (char)(i + ASCII_DIFF);
        cout << endl;
	}
    return 0;
}
