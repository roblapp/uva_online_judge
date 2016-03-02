#include <iostream>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing, ad-hoc
Algorithm: ad-hoc
*/

using namespace std;

string getWords(string soln[], string &s) {
    int cnt = 0, k = -1;
    stringstream ss("");
    bool inPostState = false;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '<') {
            cnt++;
            k++;
            inPostState = false;
        } else if (s[i] == '>') {
            cnt--;
            k++;
            inPostState = true;
        }
        if (s[i] != '<' and s[i] != '>') {
            ss << s[i];
            if (cnt != 0) {
                soln[k] += s[i];
            }
            if (inPostState) {
                soln[k] += s[i];
            }
        }
    }
    return ss.str();
}

int main() {
	int ncases;
	int ind[] = {2, 1, 0, 3};
	string sa, sb, s;
	string PATTERN("...");

	cin >> ncases; getline(cin, sa); /* drain newline */
	while (ncases--) {
        string soln[4];
        getline(cin, sa);
        getline(cin, sb);
        s = getWords(soln, sa);
        stringstream ss("");
        for (int i = 0; i < 4; i++)
            ss << soln[ind[i]];
        sb.replace(sb.find(PATTERN), 3, ss.str());
        cout << s << endl << sb << endl;
	}
    return 0;
}
