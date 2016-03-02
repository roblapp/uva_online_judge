#include <iostream>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing, string comparison
Algorithm: ad-hoc, string comparison
*/

using namespace std;

#define WRONG_ANSWER "Wrong Answer"
#define FORMAT_ERROR "Output Format Error"
#define YES "Yes"

string compare(string &sa, string &sb) {
    if (sa.compare(sb) == 0)
        return YES;
    stringstream ssa(""), ssb("");
    for (int i = 0; sa[i]; i++)
        if (!isspace(sa[i]))
            ssa << sa[i];
    for (int i = 0; sb[i]; i++)
        if (!isspace(sb[i]))
            ssb << sb[i];
    if (ssa.str().compare(ssb.str()) == 0)
        return FORMAT_ERROR;
    return WRONG_ANSWER;
}

int main() {
	int ncases;
	string sa, sb;

	cin >> ncases; getline(cin, sa); /* drain newline */
	for (int i = 1; i <= ncases; i++) {
        getline(cin, sa);
        getline(cin, sb);
        cout << "Case " << i << ": " << compare(sa, sb) << endl;
	}
    return 0;
}
