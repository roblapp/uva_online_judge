#include <iostream>
#include <cstdlib>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing, parsing
Algorithm: ad-hoc, simple parsing
*/

using namespace std;

int main() {
	string line, ans;
	int a, b, scale, ncorrect = 0;
	char opr, eq;

	while (getline(cin, line)) {
        stringstream ss(line);
        ss >> a >> opr >> b >> eq >> ans;
        scale = 1;
        if (opr == '-')
            scale = -1;
        if (ans[0] != '?' and a + scale*b == atoi(ans.c_str()))
            ncorrect++;
	}
	cout << ncorrect << endl;
    return 0;
}
