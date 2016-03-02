#include <iostream>
#include <iomanip>
#include <vector>

/*
Accepted: 0.000s
Category: string processing, ad-hoc
Algorithm: ad-hoc
*/

using namespace std;

int main() {
	int len;
	char tv;
	bool hasValidSoln, printBlankLine = false;
	string ps, es, root, suffix, LATIN_O = string(1, 243);
	vector<string> gridNames;
	gridNames.push_back("eu");
	gridNames.push_back("tu");
	gridNames.push_back("ele/ela");
	gridNames.push_back("n" + LATIN_O + "s");
	gridNames.push_back("v" + LATIN_O + "s");
	gridNames.push_back("eles/elas");

	while (cin >> ps >> es) {
        len = (int) ps.length();
        hasValidSoln = false;
        if (printBlankLine)
            cout << endl;

        printBlankLine = true;
        if (len < 2) {
            cout << ps << " (to " << es << ")" << endl;
            cout << "Unknown conjugation" << endl;
        } else {
            vector<string> v;
            suffix = ps.substr(len - 2, 2);
            tv = suffix[0];
            root = ps.substr(0, len - 2);
            if (suffix == "ar" or suffix == "er") {
                v.push_back(root + "o");
                v.push_back(root + tv + "s");
                v.push_back(root + tv);
                v.push_back(root + tv + "mos");
                v.push_back(root + tv + "is");
                v.push_back(root + tv + "m");
                hasValidSoln = true;
            } else if (suffix == "ir") {
                v.push_back(root + "o");
                v.push_back(root + "es");
                v.push_back(root + "e");
                v.push_back(root + tv + "mos");
                v.push_back(root + tv + "s");
                v.push_back(root + "em");
                hasValidSoln = true;
            }
            cout << ps << " (to " << es << ")" << endl;
            if (hasValidSoln) {
                for (int i = 0; i < (int) gridNames.size(); i++) {
                    cout << setw(10) << left << gridNames[i] << v[i] << endl;
                }
            } else {
                cout << "Unknown conjugation" << endl;
            }
        }
	}
    return 0;
}
