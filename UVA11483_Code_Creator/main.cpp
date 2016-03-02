#include <iostream>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing, ad-hoc
Algorithm: ad-hoc
*/

using namespace std;

int main() {
	int ncases, N = 1;
	string line;

	while (cin >> ncases and ncases != 0) {
        getline(cin, line); /* drain newline */
        stringstream ss("");
        ss << "Case " << N++ << ":" << endl;
        ss << "#include<string.h>" << endl;
        ss << "#include<stdio.h>" << endl;
        ss << "int main()" << endl;
        ss << "{" << endl;
        while (ncases--) {
            getline(cin, line);
            ss << "printf(\"";
            int len = (int) line.length();
            for (int i = 0; i < len; i++) {
                if (line[i] == '"' or line[i] == '\\')
                    ss << '\\';
                ss << line[i];
            }
            ss << "\\n\");" << endl;
        }
        ss << "printf(\"\\n\");" << endl;
        ss << "return 0;" << endl;
        ss << "}";
        cout << ss.str() << endl;
	}
    return 0;
}
