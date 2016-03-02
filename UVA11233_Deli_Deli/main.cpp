#include <iostream>
#include <map>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing, string comparison
Algorithm: ad-hoc, string processing
*/

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y';
}

bool isConsonant(char c) {
    return !isVowel(c);
}

string plural(map<string,string> &m, string &s) {
    map<string,string>::iterator it = m.find(s);
    if (it != m.end())
        return it->second;
    int len = (int) s.length();

    stringstream ss("");
    if (len < 2)
        ss << s << "s";
    else if (s[len-1] == 'y' and isConsonant(s[len-2]))
        ss << s.substr(0, len - 1) << "ies";
    else if (s[len-1] == 'o' or s[len-1] == 's' or s[len-1] == 'x'
               or s.substr(len-2, 2) == "sh" or s.substr(len-2, 2) == "ch")
        ss << s << "es";
    else
        ss << s << "s";
    return ss.str();
}

int main() {
	int L, N;
	string sa, sb;
	map<string,string> m;

	cin >> L >> N;
	while (L--) {
        cin >> sa >> sb;
        m[sa] = sb;
	}

	while (N--) {
        cin >> sa;
        cout << plural(m, sa) << endl;
	}
    return 0;
}
