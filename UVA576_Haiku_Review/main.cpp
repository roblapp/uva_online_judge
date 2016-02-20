#include <iostream>

/*
Accepted: 0.000s
Category: string processing
Algorithm: ad-hoc, parsing
*/

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y';
}

int countSyllables(string &s) {
    int cnt = 0;
    for (int i = 0; s[i]; i++) {
        if (i == 0 and isVowel(s[i])) {
            cnt++;
        } else if (i > 0 and isVowel(s[i]) and !isVowel(s[i-1])) {
            cnt++;
        }
    }
    return cnt;
}

int solve(string &s) {
    int i = 0, k = 0, N = s.length();
    int h[] = {5, 7, 5};
    string temp = "";

    while (k < 3) {
        if (i == N or s[i] == '/') {
            if (countSyllables(temp) != h[k])
                return k;
            k++;
            temp = "";
        } else {
            temp += s[i];
        }
        i++;
    }
    return k;
}

int main() {
	int temp;
	string line;

	while (getline(cin, line) and line != "e/o/i") {
        temp = solve(line);
        if (temp == 3)
            cout << "Y" << endl;
        else
            cout << temp + 1 << endl;
	}
    return 0;
}
