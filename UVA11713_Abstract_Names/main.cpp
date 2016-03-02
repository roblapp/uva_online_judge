#include <iostream>
#include <fstream>

/*
Accepted: 0.000s
Category: string processing, string comparison
Algorithm: ad-hoc, string comparison
*/

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y';
}

string compare(string &sa, string &sb) {
    if (sa.length() != sb.length())
        return "No";
    for (int i = 0; sa[i]; i++)
        if (sa[i] != sb[i] and !(isVowel(sa[i]) and isVowel(sb[i])))
            return "No";
    return "Yes";
}

int main() {
	int ncases;
	string sa, sb;

	cin >> ncases;
	while (ncases--) {
        cin >> sa >> sb;
        cout << compare(sa, sb) << endl;
	}
    return 0;
}
